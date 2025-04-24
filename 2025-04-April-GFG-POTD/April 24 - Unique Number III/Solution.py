class Solution:
    def getSingle(self, arr):
        freq = {}
        for num in arr:
            freq[num] = freq.get(num, 0) + 1
        
        for key, value in freq.items():
            if value == 1:
                return key
        return -1  # If not found

# Driver Code
t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))
    sol = Solution()
    print(sol.getSingle(arr))
    print("~")
