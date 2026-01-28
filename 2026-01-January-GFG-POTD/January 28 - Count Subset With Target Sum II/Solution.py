from collections import defaultdict

class Solution:
    def countSubset(self, arr, k):
        n = len(arr)
        mid = n // 2

        left = arr[:mid]
        right = arr[mid:]

        left_sum_count = defaultdict(int)
        self.generate_sums(left, 0, 0, left_sum_count)

        count = 0
        count = self.generate_and_count(
            right, 0, 0, k, left_sum_count, count
        )

        return count

    # Generate all subset sums of left half
    def generate_sums(self, arr, index, current_sum, mp):
        if index == len(arr):
            mp[current_sum] += 1
            return
        self.generate_sums(arr, index + 1, current_sum, mp)
        self.generate_sums(arr, index + 1, current_sum + arr[index], mp)

    # Generate sums of right half and count valid pairs
    def generate_and_count(self, arr, index, current_sum, k, mp, count):
        if index == len(arr):
            return count + mp[k - current_sum]
        count = self.generate_and_count(
            arr, index + 1, current_sum, k, mp, count
        )
        count = self.generate_and_count(
            arr, index + 1, current_sum + arr[index], k, mp, count
        )
        return count
