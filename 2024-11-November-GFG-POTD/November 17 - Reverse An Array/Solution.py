class Solution:
    def reverseArray(self, arr):
        start, end = 0, len(arr) - 1
        while start < end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1

def main():
    tc = int(input())
    for _ in range(tc):
        arr = list(map(int, input().split()))
        obj = Solution()
        obj.reverseArray(arr)
        print(*arr)

if __name__ == "__main__":
    main()
