from typing import List

class Solution:
    @staticmethod
    def longestSubarray(arr: List[int]) -> int:
        n = len(arr)
        next_greater = [n] * n
        prev_greater = [-1] * n
        st = []

        # Next Greater Element to the Right
        for i in range(n):
            while st and arr[st[-1]] < arr[i]:
                next_greater[st.pop()] = i
            st.append(i)

        st.clear()

        # Next Greater Element to the Left
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] < arr[i]:
                prev_greater[st.pop()] = i
            st.append(i)

        max_length = 0
        for i in range(n):
            window_size = next_greater[i] - prev_greater[i] - 1
            if window_size >= arr[i]:
                max_length = max(max_length, window_size)

        return max_length


# Example usage
arr = [2, 2, 3, 15, 8, 11, 6, 6]
print(Solution.longestSubarray(arr))  # Expected 3
