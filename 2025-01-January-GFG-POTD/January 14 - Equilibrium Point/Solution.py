# Function to find equilibrium point in the array
def findEquilibrium(arr):
    totalSum = sum(arr)  # Calculate total sum of the array
    leftSum = 0

    for i in range(len(arr)):
        totalSum -= arr[i]  # Remaining sum on the right side

        # Check if left sum equals right sum
        if leftSum == totalSum:
            return i  # Return the 0-based index of the equilibrium point

        leftSum += arr[i]  # Update left sum for next iteration

    return -1  # Return -1 if no equilibrium point is found

# Driver code
if __name__ == "__main__":
    t = int(input().strip())  # Inputting the testcases
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        print(findEquilibrium(arr))
        print("~")
