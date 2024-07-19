class Solution:
    def constructLowerArray(self, arr):
        def update(bit, index):
            while index < len(bit):
                bit[index] += 1
                index += index & -index

        def query(bit, index):
            sum = 0
            while index > 0:
                sum += bit[index]
                index -= index & -index
            return sum

        n = len(arr)
        result = [0] * n
        
        if n == 0:
            return result

        # Step 1: Normalize the numbers (convert them to ranks)
        sortedArr = sorted(arr)
        rankMap = {}
        rank = 0
        for num in sortedArr:
            if num not in rankMap:
                rankMap[num] = rank + 1
                rank += 1

        # Step 2: Use BIT to count the smaller elements
        bit = [0] * (rank + 1)

        for i in range(n - 1, -1, -1):
            currentRank = rankMap[arr[i]]
            result[i] = query(bit, currentRank - 1)
            update(bit, currentRank)

        return result

# Example usage:
sol = Solution()
arr = [12, 1, 2, 3, 0, 11, 4]
print(sol.constructLowerArray(arr))  # Output: [6, 1, 1, 1, 0, 1, 0]
