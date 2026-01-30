from collections import deque

class Solution:
    def rearrangeQueue(self, q):
        n = len(q)
        
        first_half = deque()
        
        # Move first half elements into first_half
        for _ in range(n // 2):
            first_half.append(q.popleft())
        
        # Interleave first half and second half
        while first_half:
            q.append(first_half.popleft())  # element from first half
            q.append(q.popleft())           # element from second half
