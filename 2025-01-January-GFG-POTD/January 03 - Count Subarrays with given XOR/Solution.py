class Solution:
    def subarrayXor(self, arr, k):
        # Map to store the frequency of prefixXOR
        map = {}
        prefixXOR = 0
        count = 0

        for num in arr:
            # Update prefixXOR
            prefixXOR ^= num

            # If prefixXOR itself is equal to k
            if prefixXOR == k:
                count += 1

            # Check if prefixXOR ^ k exists in map
            requiredXOR = prefixXOR ^ k
            if requiredXOR in map:
                count += map[requiredXOR]

            # Add the current prefixXOR to the map
            map[prefixXOR] = map.get(prefixXOR, 0) + 1

        return count


if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")
