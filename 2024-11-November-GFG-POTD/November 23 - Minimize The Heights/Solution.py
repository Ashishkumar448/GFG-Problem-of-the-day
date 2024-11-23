class Solution:
    def getMinDiff(self, k, arr):
        n = len(arr)
        if n == 1:
            return 0  # Only one tower, no difference
        
        arr.sort()  # Sort the array
        
        minHeight = arr[0]
        maxHeight = arr[n - 1]
        result = maxHeight - minHeight  # Initial difference
        
        for i in range(n - 1):
            newMin = min(arr[0] + k, arr[i + 1] - k)
            newMax = max(arr[i] + k, arr[n - 1] - k)
            
            result = min(result, newMax - newMin)
        
        return result

# Driver code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    
    for _ in range(t):
        k = int(input())  # Value of k
        arr = list(map(int, input().split()))  # Array input
        
        obj = Solution()
        res = obj.getMinDiff(k, arr)
        print(res)
        print("~")
