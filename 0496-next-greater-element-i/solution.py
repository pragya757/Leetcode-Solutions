class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Stack to maintain elements in decreasing order from bottom to top
        stack = []
        # Dictionary to store the next greater element for each number in nums2
        next_greater_map = {}
      
        # Traverse nums2 from right to left
        for num in nums2[::-1]:
            # Pop elements from stack that are smaller than current number
            # These cannot be the next greater element for any future number
            while stack and stack[-1] < num:
                stack.pop()
          
            # If stack is not empty, top element is the next greater element
            if stack:
                next_greater_map[num] = stack[-1]
          
            # Add current number to stack for processing future elements
            stack.append(num)
      
        # Build result array by looking up each element from nums1 in the map
        # Return -1 if no next greater element exists
        return [next_greater_map.get(num, -1) for num in nums1]
        
