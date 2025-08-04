class Solution:
    def maxRectSum(self, mat):
        n = len(mat)       # rows
        m = len(mat[0])    # cols
        max_sum = float('-inf')

        for top in range(n):
            temp = [0] * m

            for bottom in range(top, n):
                for col in range(m):
                    temp[col] += mat[bottom][col]

                current_max = self.kadane(temp)
                max_sum = max(max_sum, current_max)

        return max_sum

    def kadane(self, arr):
        max_ending_here = arr[0]
        max_so_far = arr[0]

        for x in arr[1:]:
            max_ending_here = max(x, max_ending_here + x)
            max_so_far = max(max_so_far, max_ending_here)

        return max_so_far
