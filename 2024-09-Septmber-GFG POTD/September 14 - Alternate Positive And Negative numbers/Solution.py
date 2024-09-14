class Solution:
    def rearrange(self, arr):
        pos = []  # To store positive numbers
        neg = []  # To store negative numbers

        # Separate positive and negative numbers
        for num in arr:
            if num >= 0:
                pos.append(num)
            else:
                neg.append(num)

        i = 0
        p, n = 0, 0
        turn_positive = True

        # Alternate between positive and negative numbers
        while p < len(pos) and n < len(neg):
            if turn_positive:
                arr[i] = pos[p]
                p += 1
            else:
                arr[i] = neg[n]
                n += 1
            i += 1
            turn_positive = not turn_positive

        # If there are remaining positive numbers
        while p < len(pos):
            arr[i] = pos[p]
            p += 1
            i += 1

        # If there are remaining negative numbers
        while n < len(neg):
            arr[i] = neg[n]
            n += 1
            i += 1


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        arr = list(map(int, input().split()))
        Solution().rearrange(arr)
        print(" ".join(map(str, arr)))
