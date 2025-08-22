import bisect

class Solution:
    def median(self, mat):
        n, m = len(mat), len(mat[0])

        # Find minimum and maximum
        mn = min(row[0] for row in mat)
        mx = max(row[-1] for row in mat)

        desired = (n * m + 1) // 2

        while mn < mx:
            mid = (mn + mx) // 2
            count = 0

            for row in mat:
                count += bisect.bisect_right(row, mid)

            if count < desired:
                mn = mid + 1
            else:
                mx = mid

        return mn
