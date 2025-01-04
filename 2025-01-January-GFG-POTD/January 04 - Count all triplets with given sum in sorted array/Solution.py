class Solution:
    def countTriplets(self, arr, target):
        n = len(arr)
        res = 0
        arr.sort()
        
        for i in range(n - 2):
            left, right = i + 1, n - 1
            while left < right:
                _sum = arr[i] + arr[left] + arr[right]
                if _sum < target:
                    left += 1
                elif _sum > target:
                    right -= 1
                else:
                    if arr[left] == arr[right]:
                        count = right - left + 1
                        res += count * (count - 1) // 2
                        break
                    else:
                        cnt1, cnt2 = 1, 1
                        while left + 1 < right and arr[left] == arr[left + 1]:
                            left += 1
                            cnt1 += 1
                        while right - 1 > left and arr[right] == arr[right - 1]:
                            right -= 1
                            cnt2 += 1
                        res += cnt1 * cnt2
                        left += 1
                        right -= 1
        return res


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input())
        
        ob = Solution()
        ans = ob.countTriplets(arr, target)
        print(ans)
        print("~")
