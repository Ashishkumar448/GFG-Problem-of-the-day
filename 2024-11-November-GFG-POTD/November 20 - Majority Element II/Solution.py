class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, nums):
        result = []
        if not nums:
            return result  # Return empty list if array is empty

        # Step 1: Find potential candidates using Boyer-Moore Voting Algorithm
        candidate1, candidate2, count1, count2 = 0, 0, 0, 0

        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1, count1 = num, 1
            elif count2 == 0:
                candidate2, count2 = num, 1
            else:
                count1 -= 1
                count2 -= 1

        # Step 2: Validate the candidates
        count1, count2 = 0, 0

        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1

        n = len(nums)
        if count1 > n // 3:
            result.append(candidate1)
        if count2 > n // 3:
            result.append(candidate2)

        # Return the result sorted
        result.sort()
        return result


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        nums = list(map(int, input().split()))
        ob = Solution()
        ans = ob.findMajority(nums)

        if not ans:
            print("[]")
        else:
            print(" ".join(map(str, ans)))
