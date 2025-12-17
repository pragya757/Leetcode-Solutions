class MinStack:
    def __init__(self) -> None:
        """
        Initialize the MinStack with two stacks:
        - stack: stores all elements
        - min_stack: stores the minimum element at each state
        """
        self.stack = []
        self.min_stack = [float('inf')]  # Initialize with infinity as sentinel value

    def push(self, val: int) -> None:
        """
        Push element val onto the stack.
        Also update the minimum stack with the new minimum.
      
        Args:
            val: Integer value to be pushed onto the stack
        """
        self.stack.append(val)
        # Keep track of minimum by comparing with current minimum
        self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        """
        Remove the element on top of the stack.
        Also remove the corresponding minimum from min_stack.
        """
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        """
        Get the top element of the stack without removing it.
      
        Returns:
            The top element of the stack
        """
        return self.stack[-1]

    def getMin(self) -> int:
        """
        Retrieve the minimum element in the stack in O(1) time.
      
        Returns:
            The minimum element currently in the stack
        """
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
        
        



