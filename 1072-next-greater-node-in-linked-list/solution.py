# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional, List

class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        # Convert linked list to array for easier processing
        values = []
        current = head
        while current:
            values.append(current.val)
            current = current.next
      
        # Initialize monotonic stack and result array
        stack = []  # Monotonic decreasing stack to track potential next larger elements
        n = len(values)
        result = [0] * n  # Initialize result array with zeros (default when no larger element exists)
      
        # Traverse the array from right to left
        for i in range(n - 1, -1, -1):
            # Pop elements from stack that are smaller or equal to current element
            # They cannot be the next larger element for any future elements
            while stack and stack[-1] <= values[i]:
                stack.pop()
          
            # If stack is not empty, top element is the next larger element
            if stack:
                result[i] = stack[-1]
          
            # Add current element to stack for future comparisons
            stack.append(values[i])
      
        return result

