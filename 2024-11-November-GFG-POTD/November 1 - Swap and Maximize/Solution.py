class Solution:
    def maxSum(self, arr):
        # Step 1: Sort the array
        arr.sort()
        
        # Create a new array to store elements in high-low order
        newArr = [0] * len(arr)
        
        # Step 2: Fill newArr with elements in alternating high-low order
        left, right = 0, len(arr) - 1
        index = 0
        
        while left <= right:
            if index % 2 == 0:
                newArr[index] = arr[left]
                left += 1
            else:
                newArr[index] = arr[right]
                right -= 1
            index += 1
        
        # Step 3: Calculate the sum of absolute differences
        maxSum = 0
        for i in range(len(newArr) - 1):
            maxSum += abs(newArr[i] - newArr[i + 1])
        
        # Add the absolute difference between the last and first element to close the loop
        maxSum += abs(newArr[-1] - newArr[0])
        
        return maxSum

# Driver code
if __name__ == "__main__":
    testcases = int(input().strip())
    for _ in range(testcases):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        print(solution.maxSum(arr))
        print("~")
