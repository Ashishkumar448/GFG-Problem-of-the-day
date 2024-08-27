class Solution:
    def findMaxDiff(self, arr):
        n = len(arr)
        
        # Arrays to store the nearest smaller elements on the left and right
        leftSmaller = [0] * n
        rightSmaller = [0] * n
        
        # Fill the leftSmaller array
        stack = []
        for i in range(n):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            leftSmaller[i] = 0 if not stack else stack[-1]
            stack.append(arr[i])
        
        # Clear the stack and fill the rightSmaller array
        stack.clear()
        for i in range(n - 1, -1, -1):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            rightSmaller[i] = 0 if not stack else stack[-1]
            stack.append(arr[i])
        
        # Find the maximum absolute difference
        maxDiff = 0
        for i in range(n):
            diff = abs(leftSmaller[i] - rightSmaller[i])
            if diff > maxDiff:
                maxDiff = diff
        
        return maxDiff

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.findMaxDiff(arr))
