# Rotate and Delete Solution in Python

class Solution:
    def rotateDelete(self, arr):
        n = len(arr)
        step = 1

        while n > 1:
            # Rotate: move the last element to the front
            arr = [arr[-1]] + arr[:-1]

            # Delete: delete the element at index (n - step)
            remove_index = n - step
            if remove_index < 0:
                remove_index = 0  # If step exceeds the current size, remove the first element
            arr.pop(remove_index)

            # Reduce the size of the list after removal
            n = len(arr)
            step += 1

        # Return the last remaining element
        return arr[0]

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))

        obj = Solution()
        res = obj.rotateDelete(arr)
        print(res)
