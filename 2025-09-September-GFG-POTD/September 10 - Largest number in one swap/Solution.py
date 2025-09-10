class Solution:
    def largestSwap(self, s: str) -> str:
        arr = list(s)
        n = len(arr)

        # Store rightmost occurrence of each digit
        rightmost = [-1] * 10
        for i in range(n):
            rightmost[int(arr[i])] = i

        # Try to find the first place to swap
        for i in range(n):
            currDigit = int(arr[i])
            for d in range(9, currDigit, -1):
                if rightmost[d] > i:
                    # Swap
                    arr[i], arr[rightmost[d]] = arr[rightmost[d]], arr[i]
                    return "".join(arr)

        # If no swap improves the number
        return s
