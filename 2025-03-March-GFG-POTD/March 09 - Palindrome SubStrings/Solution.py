def countPS(s):
    n = len(s)
    dp = [[False] * n for _ in range(n)]
    count = 0

    # Checking substrings of length 1 (ignored in count)
    for i in range(n):
        dp[i][i] = True

    # Checking substrings of length 2
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = True
            count += 1

    # Checking substrings of length ≥3
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j] and dp[i + 1][j - 1]:
                dp[i][j] = True
                count += 1

    return count


# Driver Code
t = int(input())
for _ in range(t):
    s = input().strip()
    print(countPS(s))
    print("~")
