class Solution:
    def countFreq(self, arr, target):
        # Find the first occurrence of the target
        first = self.findFirstOccurrence(arr, target)
        if first == -1:
            # Target not found in the array
            return 0

        # Find the last occurrence of the target
        last = self.findLastOccurrence(arr, target)

        # The number of occurrences is (last - first + 1)
        return last - first + 1

    def findFirstOccurrence(self, arr, target):
        low, high = 0, len(arr) - 1
        result = -1

        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] == target:
                result = mid
                high = mid - 1  # Narrow search to the left
            elif arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        return result

    def findLastOccurrence(self, arr, target):
        low, high = 0, len(arr) - 1
        result = -1

        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] == target:
                result = mid
                low = mid + 1  # Narrow search to the right
            elif arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        return result


# Driver code
if __name__ == "__main__":
    tc = int(input().strip())

    for _ in range(tc):
        arr = list(map(int, input().strip().split()))
        target = int(input().strip())
        sln = Solution()
        print(sln.countFreq(arr, target))
        print("~")
