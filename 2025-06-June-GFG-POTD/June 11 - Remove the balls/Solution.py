from typing import List

class Solution:
    def findLength(self, color: List[int], radius: List[int]) -> int:
        stack = []

        for c, r in zip(color, radius):
            if stack and stack[-1] == (c, r):
                stack.pop()  # Remove matching pair
            else:
                stack.append((c, r))

        return len(stack)  # Remaining balls
