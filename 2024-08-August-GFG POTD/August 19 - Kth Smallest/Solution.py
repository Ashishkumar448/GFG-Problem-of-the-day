def kthSmallest(arr, k):
    # Sort the array
    arr.sort()

    # Return the k-1 index element because array index starts from 0
    return arr[k - 1]

t = int(input().strip())
for _ in range(t):
    line = input().strip()
    array = list(map(int, line.split()))
    key = int(input().strip())
    print(kthSmallest(array, key))
