from collections import deque

def maxOfSubarrays(arr, k):
    result = []
    dq = deque()

    for i in range(len(arr)):
        # Remove elements from the back of the deque that are smaller than the current element
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()

        # Add the current index to the deque
        dq.append(i)

        # Remove elements from the front of the deque that are out of the current window
        if dq and dq[0] <= i - k:
            dq.popleft()

        # Add the maximum element of the current window to the result if the window is full
        if i >= k - 1:
            result.append(arr[dq[0]])

    return result

# Example usage
t = int(input())

while t > 0:
    t -= 1
    arr = list(map(int, input().split()))
    k = int(input())

    res = maxOfSubarrays(arr, k)

    # printing the elements of the list
    for i in res:
        print(i, end=" ")
    print()
    print("~")
