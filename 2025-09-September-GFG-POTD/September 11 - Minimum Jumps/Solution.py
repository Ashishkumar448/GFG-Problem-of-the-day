class Solution:
    def minJumps(self, arr):
        n = len(arr)

        # If the first element is 0, we can't move anywhere
        if n <= 1:
            return 0
        if arr[0] == 0:
            return -1

        jumps = 0
        farthest = 0
        current_end = 0

        for i in range(n - 1):
            farthest = max(farthest, i + arr[i])

            # If we reach the end of the current jump range
            if i == current_end:
                jumps += 1
                current_end = farthest

                # If we cannot move forward
                if current_end <= i:
                    return -1

                # If we can reach or cross the last index
                if current_end >= n - 1:
                    return jumps

        return -1
