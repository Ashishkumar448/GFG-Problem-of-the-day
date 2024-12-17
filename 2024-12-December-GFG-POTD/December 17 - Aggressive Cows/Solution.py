class Solution:
    def aggressiveCows(self, stalls, k):
        # Sort the stall positions to facilitate binary search
        stalls.sort()

        # Define the binary search range
        low = 1  # Minimum possible distance
        high = stalls[-1] - stalls[0]  # Maximum possible distance
        result = 0

        # Binary search to find the largest minimum distance
        while low <= high:
            mid = low + (high - low) // 2

            if self.canPlaceCows(stalls, k, mid):
                result = mid  # Update result if cows can be placed
                low = mid + 1  # Try for a larger distance
            else:
                high = mid - 1  # Try for a smaller distance

        return result

    def canPlaceCows(self, stalls, k, distance):
        count = 1  # Place the first cow in the first stall
        lastPlacedCow = stalls[0]

        for i in range(1, len(stalls)):
            if stalls[i] - lastPlacedCow >= distance:
                count += 1
                lastPlacedCow = stalls[i]
                if count == k:
                    return True

        return False


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        stalls = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        print(obj.aggressiveCows(stalls, k))
