class Solution:
    def countgroup(self, arr):
        mod = 10**9 + 7
        xr = 0
        n = len(arr)
        
        # XOR all elements
        for num in arr:
            xr ^= num
        
        # If the XOR is non-zero, return 0
        if xr != 0:
            return 0
        
        # Calculate the result
        ans = 1
        for i in range(n - 1):
            ans = (ans * 2) % mod
        
        return ans - 1

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        ans = obj.countgroup(arr)
        print(ans)
