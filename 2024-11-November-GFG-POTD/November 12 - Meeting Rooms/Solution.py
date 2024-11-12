class Solution:
    def canAttend(self, arr):
        # Sort meetings by start time
        arr.sort(key=lambda x: x[0])

        # Check for any overlaps
        for i in range(1, len(arr)):
            # If current meeting starts before the previous one ends, return False
            if arr[i][0] < arr[i - 1][1]:
                return False
        # No overlaps found, return True
        return True


if __name__ == "__main__":
    T = int(input().strip())
    for _ in range(T):
        n = int(input().strip())
        arr = [list(map(int, input().strip().split())) for _ in range(n)]
        obj = Solution()
        ans = obj.canAttend(arr)
        print("true" if ans else "false")
