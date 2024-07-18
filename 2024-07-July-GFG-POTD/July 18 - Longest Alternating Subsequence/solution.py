def las(arr):
    n = len(arr)
    if n == 0:
        return 0

    inc, dec = 1, 1

    for i in range(1, n):
        if arr[i] > arr[i - 1]:
            inc = dec + 1
        elif arr[i] < arr[i - 1]:
            dec = inc + 1

    return max(inc, dec)

arr = [1, 5, 4]
print("Length of Longest Alternating Subsequence:", las(arr))