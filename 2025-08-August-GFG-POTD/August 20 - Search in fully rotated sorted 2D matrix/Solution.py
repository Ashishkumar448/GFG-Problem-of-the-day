class Solution:
    def searchMatrix(self, mat, x):
        n, m = len(mat), len(mat[0])
        low, high = 0, n * m - 1

        while low <= high:
            mid = (low + high) // 2
            row, col = divmod(mid, m)
            val = mat[row][col]

            if val == x:
                return True

            lowVal = mat[low // m][low % m]
            highVal = mat[high // m][high % m]

            # Left half sorted
            if lowVal <= val:
                if x >= lowVal and x < val:
                    high = mid - 1
                else:
                    low = mid + 1
            # Right half sorted
            else:
                if x > val and x <= highVal:
                    low = mid + 1
                else:
                    high = mid - 1

        return False
