class Solution:
    # Function to count the number of possible triangles.
    def countTriangles(self, arr):
        # Sort the array to simplify the triangle condition check
        arr.sort()

        n = len(arr)
        count = 0

        # Fix the largest side one by one
        for i in range(n - 1, 1, -1):
            left = 0
            right = i - 1

            # Use two pointers to find valid pairs
            while left < right:
                # Check if the sum of arr[left] and arr[right] is greater than arr[i]
                if arr[left] + arr[right] > arr[i]:
                    # All elements between left and right form a valid triangle
                    count += (right - left)
                    right -= 1
                else:
                    # Move the left pointer forward
                    left += 1

        return count


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        obj = Solution()
        print(obj.countTriangles(arr))
