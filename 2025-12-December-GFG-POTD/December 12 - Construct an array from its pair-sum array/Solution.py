import math

class Solution:
    def constructArr(self, arr):
        res = []
        M = len(arr)

        discriminant = 1 + 8 * M
        n = int((1 + math.sqrt(discriminant)) / 2)

        # Edge case: n = 2
        if n == 2:
            val1 = arr[0] // 2
            val2 = arr[0] - val1
            res.append(val1)
            res.append(val2)
            return res

        sumABC = arr[0] + arr[1] - arr[n - 1]
        x0 = sumABC // 2
        res.append(x0)

        for i in range(n - 1):
            res.append(arr[i] - x0)

        return res
