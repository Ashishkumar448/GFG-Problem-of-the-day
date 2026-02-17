class Solution:
    def overlapInt(self, arr):
        events = []
        
        for start, end in arr:
            events.append((start, 1))        # start
            events.append((end + 1, -1))     # end + 1 (inclusive)
        
        # Sort by:
        # 1. time ascending
        # 2. if same time -> -1 before +1
        events.sort(key=lambda x: (x[0], x[1]))
        
        current = 0
        max_overlap = 0
        
        for time, val in events:
            current += val
            max_overlap = max(max_overlap, current)
        
        return max_overlap
