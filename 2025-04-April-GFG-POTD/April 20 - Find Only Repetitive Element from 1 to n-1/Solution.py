# Python solution using XOR
class Solution:
    def findDuplicate(self, arr):
        n = len(arr)
        xorArr = 0
        for num in arr:
            xorArr ^= num

        xorRange = 0
        for i in range(1, n):
            xorRange ^= i

        return xorArr ^ xorRange

# Driver code
t = int(input())
for _ in range(t):
    arr = list(map(int, input().strip().split()))
    ob = Solution()
    print(ob.findDuplicate(arr))
    print("~")
