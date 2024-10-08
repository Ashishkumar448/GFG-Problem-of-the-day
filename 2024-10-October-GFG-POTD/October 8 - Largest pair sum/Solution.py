class Solution:
    def pairsum(self, arr):
        # Step 1: Sort the array
        arr.sort()

        # Step 2: Return the sum of the two largest elements
        return arr[-1] + arr[-2]

def main():
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        res = obj.pairsum(arr)
        print(res)

if __name__ == "__main__":
    main()
