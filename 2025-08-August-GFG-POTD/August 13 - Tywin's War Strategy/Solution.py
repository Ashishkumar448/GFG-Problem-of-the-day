class Solution:
    def minSoldiers(self, arr, k):
        n = len(arr)
        required = (n + 1) // 2  # ceil(n / 2)
        lucky_count = 0
        add_list = []

        for num in arr:
            if num % k == 0:
                lucky_count += 1
            else:
                add_list.append(k - (num % k))

        if lucky_count >= required:
            return 0

        add_list.sort()
        to_make_lucky = required - lucky_count
        soldiers_needed = sum(add_list[:to_make_lucky])

        return soldiers_needed


# Example usage
sol = Solution()
print(sol.minSoldiers([3, 5, 6, 7, 9, 10], 4))  # Output: 4
