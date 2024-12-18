class Solution:
    def findPages(self, arr, k):
        if len(arr) < k:  # Not enough books for students
            return -1

        low, high = max(arr), sum(arr)  # Range for binary search
        result = -1

        while low <= high:
            mid = low + (high - low) // 2

            if self.isFeasible(arr, k, mid):
                result = mid  # Valid allocation found, try for a smaller maximum
                high = mid - 1
            else:
                low = mid + 1  # Increase the allowed maximum

        return result

    def isFeasible(self, arr, k, maxPages):
        studentsRequired, currentPages = 1, 0

        for pages in arr:
            if currentPages + pages > maxPages:
                studentsRequired += 1  # Allocate to a new student
                currentPages = pages

                if studentsRequired > k:  # More students needed than available
                    return False
            else:
                currentPages += pages

        return True


# Driver Code
if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())
        sln = Solution()
        print(sln.findPages(arr, k))
