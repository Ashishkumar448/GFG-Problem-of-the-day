def findSmallest(arr):
    # Sort the array
    arr.sort()
    
    # Initialize the smallest number that cannot be formed
    res = 1  # Start with 1 as the smallest positive number
    
    # Traverse the array and find the smallest missing number
    for i in range(len(arr)):
        if arr[i] <= res:
            res += arr[i]
        else:
            break
    
    return res

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        print(findSmallest(arr))
