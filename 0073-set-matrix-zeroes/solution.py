from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])
        zero_rows = set()
        zero_cols = set()

        # Step 1: Identify all rows and columns that need to be zeroed
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    zero_rows.add(i)
                    zero_cols.add(j)

        # Step 2: Set the corresponding rows and columns to zero
        for i in range(n):
            for j in range(m):
                if i in zero_rows or j in zero_cols:
                    matrix[i][j] = 0

# Test code (useful for running locally)
if __name__ == "__main__":
    matrix = [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]
    print("Original Matrix:")
    for row in matrix:
        print(row)

    Solution().setZeroes(matrix)

    print("\nFinal Matrix:")
    for row in matrix:
        print(row)

