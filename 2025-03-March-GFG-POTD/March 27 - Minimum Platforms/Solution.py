def findPlatform(arr, dep):
    arr.sort()
    dep.sort()
    
    n = len(arr)
    platforms = 1
    max_platforms = 1
    i, j = 1, 0

    while i < n and j < n:
        if arr[i] <= dep[j]:  
            # A train is arriving before or at the same time another departs
            platforms += 1
            i += 1
        else:  
            # A train has departed, freeing a platform
            platforms -= 1
            j += 1
        max_platforms = max(max_platforms, platforms)

    return max_platforms


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        # First array input (arrival times)
        arr = list(map(int, input().strip().split()))

        # Second array input (departure times)
        dep = list(map(int, input().strip().split()))

        print(findPlatform(arr, dep))
        print("~")
