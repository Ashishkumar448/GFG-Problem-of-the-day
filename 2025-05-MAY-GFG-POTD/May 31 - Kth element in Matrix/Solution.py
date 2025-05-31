class Solution:
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        low, high = matrix[0][0], matrix[-1][-1]

        while low < high:
            mid = (low + high) // 2
            count = self.countLessEqual(matrix, mid, n)

            if count < k:
                low = mid + 1
            else:
                high = mid

        return low

    def countLessEqual(self, matrix, mid, n):
        count = 0
        row, col = n - 1, 0

        while row >= 0 and col < n:
            if matrix[row][col] <= mid:
                count += row + 1
                col += 1
            else:
                row -= 1

        return count
