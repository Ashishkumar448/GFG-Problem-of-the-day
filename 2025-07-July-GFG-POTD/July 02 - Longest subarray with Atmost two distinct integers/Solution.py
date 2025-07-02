from collections import defaultdict

class Solution:
    def totalElements(self, arr):
        count = defaultdict(int)
        max_len = start = 0

        for end in range(len(arr)):
            count[arr[end]] += 1

            while len(count) > 2:
                count[arr[start]] -= 1
                if count[arr[start]] == 0:
                    del count[arr[start]]
                start += 1

            max_len = max(max_len, end - start + 1)

        return max_len
