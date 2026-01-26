class Solution:
    def permuteDist(self, arr):
        res = []
        self.backtrack(arr, 0, res)
        return res

    def backtrack(self, arr, idx, res):
        if idx == len(arr):
            res.append(arr[:])  # copy current permutation
            return

        for i in range(idx, len(arr)):
            arr[i], arr[idx] = arr[idx], arr[i]
            self.backtrack(arr, idx + 1, res)
            arr[i], arr[idx] = arr[idx], arr[i]  # backtrack
