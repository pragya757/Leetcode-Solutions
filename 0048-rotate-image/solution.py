class Solution(object):
  def rotate(self, matrix):
    """
    :type matrix: List[List[int]]
    :rtype: void Do not return anything, modify matrix in-place instead.
    """
    if len(matrix) == 0:
      return
    h = len(matrix)
    w = len(matrix[0])
    for i in range(0, h): # mirror
      for j in range(0, w / 2):
        matrix[i][j], matrix[i][w - j - 1] = matrix[i][w - j - 1], matrix[i][j]

    for i in range(0, h): # transpos
      for j in range(0, w - 1 - i):
        matrix[i][j], matrix[w - 1 - j][h - 1 - i] = matrix[w - 1 - j][h - 1 - i], matrix[i][j]


############

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i - 1][j], matrix[i][j]
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

