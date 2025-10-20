class Solution:
    def __init__(self):
        self.memo = {}

    def numBST(self, n):
        if n <= 1:
            return 1
        if n in self.memo:
            return self.memo[n]
        
        total = 0
        for i in range(1, n + 1):
            total += self.numBST(i - 1) * self.numBST(n - i)
        
        self.memo[n] = total
        return total

    def countBSTs(self, arr):
        n = len(arr)
        sorted_arr = sorted(arr)
        bst_map = {}

        for i in range(n):
            left_count = i
            right_count = n - i - 1
            count = self.numBST(left_count) * self.numBST(right_count)
            bst_map[sorted_arr[i]] = count

        result = [bst_map[val] for val in arr]
        return result


# Example usage
sol = Solution()
print(sol.countBSTs([2, 1, 3]))  # Output: [1, 2, 2]
