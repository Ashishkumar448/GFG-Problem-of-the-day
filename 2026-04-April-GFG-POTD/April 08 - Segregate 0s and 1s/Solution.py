class Solution:
    def segregate0and1(self, arr):
        countZero = 0

        # Count zeros
        for num in arr:
            if num == 0:
                countZero += 1

        # Fill array
        for i in range(len(arr)):
            if i < countZero:
                arr[i] = 0
            else:
                arr[i] = 1
