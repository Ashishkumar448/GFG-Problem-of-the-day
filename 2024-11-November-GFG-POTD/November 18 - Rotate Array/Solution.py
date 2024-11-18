# User function Template for Python

def rotateArr(arr, d, n):
    # Handle cases where d >= n
    d = d % n

    # Step 1: Reverse the first d elements
    arr[:d] = reversed(arr[:d])

    # Step 2: Reverse the remaining elements
    arr[d:] = reversed(arr[d:])

    # Step 3: Reverse the entire array
    arr.reverse()


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        array = list(map(int, input().strip().split()))
        d = int(input().strip())  # rotation count
        n = len(array)

        rotateArr(array, d, n)

        print(" ".join(map(str, array)))
        print("~")
