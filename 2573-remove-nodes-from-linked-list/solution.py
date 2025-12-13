# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Remove nodes from linked list where there exists a node with greater value to its right.
      
        Args:
            head: Head of the input linked list
          
        Returns:
            Head of the modified linked list with nodes removed
        """
        # Extract all values from the linked list into an array
        values = []
        current = head
        while current:
            values.append(current.val)
            current = current.next
      
        # Use monotonic decreasing stack to keep only valid nodes
        # A node is valid if no greater value exists to its right
        stack = []
        for value in values:
            # Remove all smaller values from stack when encountering a larger value
            while stack and stack[-1] < value:
                stack.pop()
            stack.append(value)
      
        # Reconstruct the linked list from the remaining values in stack
        dummy_head = ListNode()
        current = dummy_head
        for value in stack:
            current.next = ListNode(value)
            current = current.next
          
        return dummy_head.next
