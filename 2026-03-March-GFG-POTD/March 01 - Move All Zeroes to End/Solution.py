class Solution:
    def pushZerosToEnd(self, arr):
        j = 0  # Pointer for next non-zero position
        
        for i in range(len(arr)):
            if arr[i] != 0:
                # Swap arr[i] and arr[j]
                arr[i], arr[j] = arr[j], arr[i]
                j += 1
