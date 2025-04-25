class Solution:
    def majorityElement(self, arr):
        count = 0
        candidate = -1

        # Step 1: Find a candidate
        for num in arr:
            if count == 0:
                candidate = num
                count = 1
            elif num == candidate:
                count += 1
            else:
                count -= 1

        # Step 2: Verify the candidate
        if arr.count(candidate) > len(arr) // 2:
            return candidate
        return -1


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        sol = Solution()
        print(sol.majorityElement(arr))
        print("~")
