class Solution:
    def findTriplets(self, arr):
        res = []
        n = len(arr)

        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    if arr[i] + arr[j] + arr[k] == 0:
                        res.append([i, j, k])

        return res


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        nums = list(map(int, input().split()))

        obj = Solution()
        res = obj.findTriplets(nums)

        res.sort(key=lambda x: (x[0], x[1], x[2]))

        if not res:
            print("[]")
        else:
            for triplet in res:
                print(" ".join(map(str, triplet)))
        print("~")
