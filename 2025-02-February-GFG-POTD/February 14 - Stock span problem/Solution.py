// Python Implementation
def calculateSpan(arr):
    result = []
    stack = []
    
    for i in range(len(arr)):
        while stack and arr[stack[-1]] <= arr[i]:
            stack.pop()
        
        if not stack:
            result.append(i + 1)
        else:
            result.append(i - stack[-1])
        
        stack.append(i)
    
    return result
