class Solution:
    def findDuplicates(self, arr):
        result = []

        for i in range(len(arr)):
            index = abs(arr[i]) - 1

            if arr[index] < 0:
                result.append(index + 1)
            else:
                arr[index] = -arr[index]

        return result
