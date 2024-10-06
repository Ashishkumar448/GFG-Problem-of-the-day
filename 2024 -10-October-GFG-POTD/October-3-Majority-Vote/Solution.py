# Function to find the majority elements in the array
class Solution:
    def findMajority(self, arr):
        count1, count2, candidate1, candidate2 = 0, 0, None, None

        # Phase 1: Find potential candidates for the majority element
        for num in arr:
            if candidate1 is not None and candidate1 == num:
                count1 += 1
            elif candidate2 is not None and candidate2 == num:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        # Phase 2: Validate the candidates
        count1, count2 = 0, 0
        for num in arr:
            if candidate1 == num:
                count1 += 1
            elif candidate2 == num:
                count2 += 1

        result = []
        if count1 > len(arr) // 3:
            result.append(candidate1)
        if count2 > len(arr) // 3:
            result.append(candidate2)

        return result


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        ans = obj.findMajority(arr)
        print(" ".join(map(str, ans)))
