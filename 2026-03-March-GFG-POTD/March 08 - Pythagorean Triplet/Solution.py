class Solution:
    def pythagoreanTriplet(self, arr):
        n = len(arr)
        
        present = [False] * 1000001

        # store squares
        for x in arr:
            present[x * x] = True

        # check pairs
        for i in range(n):
            for j in range(i + 1, n):
                s = arr[i]*arr[i] + arr[j]*arr[j]
                if s <= 1000000 and present[s]:
                    return True

        return False
