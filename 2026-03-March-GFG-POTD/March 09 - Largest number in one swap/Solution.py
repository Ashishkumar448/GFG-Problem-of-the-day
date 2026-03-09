class Solution:
    def largestSwap(self, s: str) -> str:
        arr = list(s)
        n = len(arr)

        maxIdx = [0] * n
        maxIdx[n - 1] = n - 1

        for i in range(n - 2, -1, -1):
            if arr[i] > arr[maxIdx[i + 1]]:
                maxIdx[i] = i
            else:
                maxIdx[i] = maxIdx[i + 1]

        for i in range(n):
            if arr[i] < arr[maxIdx[i]]:
                arr[i], arr[maxIdx[i]] = arr[maxIdx[i]], arr[i]
                break

        return "".join(arr)
