class Solution:
    def countPairs(self, arr, target):
        freq_map = {}  # Dictionary to store frequencies of elements
        count = 0

        # Traverse the array
        for num in arr:
            complement = target - num

            # If the complement is already in the map, increment the count
            if complement in freq_map:
                count += freq_map[complement]

            # Add the current number to the map
            freq_map[num] = freq_map.get(num, 0) + 1

        return count

# Driver code
if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        nums = list(map(int, input().split()))
        target = int(input())

        obj = Solution()
        print(obj.countPairs(nums, target))
        print("~")
