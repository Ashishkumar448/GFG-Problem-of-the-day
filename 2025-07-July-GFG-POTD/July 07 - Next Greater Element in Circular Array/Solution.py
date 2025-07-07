from typing import List

class Solution:
    def nextLargerElement(self, arr: List[int]) -> List[int]:
        n = len(arr)
        res = [-1] * n
        stack = []

        for i in range(2 * n - 1, -1, -1):
            index = i % n
            while stack and arr[stack[-1]] <= arr[index]:
                stack.pop()
            if i < n:
                if stack:
                    res[index] = arr[stack[-1]]
            stack.append(index)

        return res
