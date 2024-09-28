class Solution:
    # Function to find the maximum number of consecutive steps
    # where we see an increase in altitude with each step.
    def maxStep(self, arr):
        max_steps = 0  # Variable to keep track of the maximum steps
        current_steps = 0  # Variable to count current consecutive steps

        # Traverse through the array of building heights
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                current_steps += 1  # Increment if the current building is taller
                max_steps = max(max_steps, current_steps)  # Update max_steps
            else:
                current_steps = 0  # Reset if no increase in height

        return max_steps

# Driver Code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))  # Input building heights as a list
        sol = Solution()
        print(sol.maxStep(arr))  # Output the result

