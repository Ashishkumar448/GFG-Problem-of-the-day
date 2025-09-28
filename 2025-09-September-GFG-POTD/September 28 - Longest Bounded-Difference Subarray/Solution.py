from collections import deque

class Solution:
    def longestSubarray(self, arr, x):
        n = len(arr)
        minDeque, maxDeque = deque(), deque()
        
        left = 0
        bestLen, bestStart = 0, 0
        
        for right in range(n):
            # Maintain decreasing deque for max
            while maxDeque and arr[maxDeque[-1]] < arr[right]:
                maxDeque.pop()
            maxDeque.append(right)
            
            # Maintain increasing deque for min
            while minDeque and arr[minDeque[-1]] > arr[right]:
                minDeque.pop()
            minDeque.append(right)
            
            # Shrink window if difference exceeds x
            while arr[maxDeque[0]] - arr[minDeque[0]] > x:
                if maxDeque[0] == left:
                    maxDeque.popleft()
                if minDeque[0] == left:
                    minDeque.popleft()
                left += 1
            
            # Update best window
            if right - left + 1 > bestLen:
                bestLen = right - left + 1
                bestStart = left
        
        return arr[bestStart:bestStart + bestLen]
