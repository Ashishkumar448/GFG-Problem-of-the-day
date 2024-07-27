# User function Template for python3

class Solution:
    def countMin(self, str):
        # code here
        n = len(str)
        rev = str[::-1]
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if str[i - 1] == rev[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        lps = dp[n][n]
        return n - lps

# Driver code to test the function 
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        str = data[index]
        index += 1
        ob = Solution()
        results.append(ob.countMin(str))
    
    for result in results:
        print(result)
