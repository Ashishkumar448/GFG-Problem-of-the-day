def lis(arr):
    n = len(arr)
    dp = [1] * n  # dp[i] will store the length of LIS ending at index i
    
    # Compute the length of LIS ending at each position
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j]:
                # Update dp[i] if a longer increasing subsequence is found
                dp[i] = max(dp[i], dp[j] + 1)
    
    # Find the maximum length in the dp array
    return max(dp)

# Driver code
t = int(input())  # Number of test cases
for _ in range(t):
    arr = list(map(int, input().split()))  # Read the input array
    
    # Call the solution method and print the result
    print(lis(arr))
    print("~")
