# User function Template for Python3

class Solution:
    def rowWithMax1s(self, arr):
        n = len(arr)
        m = len(arr[0])

        rowIndex = -1
        j = m - 1  # start from top-right corner

        for i in range(n):
            while j >= 0 and arr[i][j] == 1:
                rowIndex = i  # update row index
                j -= 1        # move left

        return rowIndex
