from typing import List

class Solution:
    def nextGreater(self, arr: List[int]) -> List[int]:
        n = len(arr)
        res = [-1] * n
        st = []

        # Traverse array twice
        for i in range(2 * n):
            num = arr[i % n]

            while st and arr[st[-1]] < num:
                idx = st.pop()
                res[idx] = num

            # Only push indices in first pass
            if i < n:
                st.append(i)

        return res


# Example usage
sol = Solution()
arr = [1, 3, 2, 4]
print(sol.nextGreater(arr))  # [3, 4, 4, -1]
