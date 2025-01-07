from collections import defaultdict

class Solution:
    def countPairs(self, arr, target):
        freq = defaultdict(int)
        res = 0

        for num in arr:
            res += freq[target - num]
            freq[num] += 1

        return res

if __name__ == "__main__":
    t = int(input())  # Input the number of test cases
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        target = int(input())

        obj = Solution()
        res = obj.countPairs(arr, target)
        print(res)
        print("~")
s
