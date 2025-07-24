class Solution:
    def getLastMoment(self, n: int, left: list[int], right: list[int]) -> int:
        max_time = 0

        # Time for ants moving left: distance to 0
        for pos in left:
            max_time = max(max_time, pos)

        # Time for ants moving right: distance to n
        for pos in right:
            max_time = max(max_time, n - pos)

        return max_time
