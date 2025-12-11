# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Swaps every two adjacent nodes in a linked list recursively.
      
        Args:
            head: The head of the linked list
          
        Returns:
            The new head of the linked list after swapping pairs
        """
        # Base case: if list is empty or has only one node, no swap needed
        if head is None or head.next is None:
            return head
      
        # Recursively swap the remaining pairs after the current pair
        remaining_swapped = self.swapPairs(head.next.next)
      
        # Store the second node which will become the new first node
        new_first = head.next
      
        # Make the second node point to the first node (swap)
        new_first.next = head
      
        # Connect the first node (now second) to the rest of the swapped list
        head.next = remaining_swapped
      
        # Return the new first node of this pair
        return new_first

