class Solution:
    def twoSum(self, arr, target):
        num_map = {}

        for i, num in enumerate(arr):
            complement = target - num

            if complement in num_map:
                return True

            num_map[num] = i

        return False


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        x = int(input())
        arr = list(map(int, input().split()))

        obj = Solution()
        ans = obj.twoSum(arr, x)
        print("true" if ans else "false")
        print("~")
