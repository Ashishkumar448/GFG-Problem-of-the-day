class Solution:
    def sumSubMins(self, arr):
        n = len(arr)
        
        ple = [0] * n
        nle = [0] * n
        
        stack = []
        
        # Previous Less Element
        for i in range(n):
            while stack and arr[stack[-1]] > arr[i]:
                stack.pop()
            
            ple[i] = -1 if not stack else stack[-1]
            stack.append(i)
        
        stack.clear()
        
        # Next Less Element
        for i in range(n-1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            
            nle[i] = n if not stack else stack[-1]
            stack.append(i)
        
        total = 0
        
        for i in range(n):
            left = i - ple[i]
            right = nle[i] - i
            
            total += arr[i] * left * right
        
        return total
