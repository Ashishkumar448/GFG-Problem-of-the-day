class Solution:
    def findTwoElement(self, arr):
        n = len(arr)
        repeating = -1
        missing = -1

        # STEP 1: Find repeating using index marking
        for i in range(n):
            idx = abs(arr[i]) - 1
            if arr[idx] < 0:
                repeating = abs(arr[i])
            else:
                arr[idx] = -arr[idx]

        # STEP 2: Find missing
        for i in range(n):
            if arr[i] > 0:
                missing = i + 1
                break

        return [repeating, missing]
