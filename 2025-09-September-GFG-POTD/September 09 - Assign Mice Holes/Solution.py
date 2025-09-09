class Solution:
    def assignHole(self, mices: list[int], holes: list[int]) -> int:
        mices.sort()
        holes.sort()
        
        max_time = 0
        for i in range(len(mices)):
            max_time = max(max_time, abs(mices[i] - holes[i]))
        return max_time
