class Solution:
    # Function to determine if array arr can be split into three equal sum sets.
    def findSplit(self, arr):
        result = [-1, -1]
        
        totalSum = sum(arr)
        
        # If totalSum is not divisible by 3, we cannot split the array.
        if totalSum % 3 != 0:
            return result
        
        targetSum = totalSum // 3
        runningSum = 0
        count = 0
        
        # Traverse the array to find the split points.
        for i in range(len(arr)):
            runningSum += arr[i]
            
            if runningSum == targetSum:
                runningSum = 0  # Reset runningSum for next part
                count += 1
                
                # Set the split points when we find the first two equal parts
                if count == 1:
                    result[0] = i
                elif count == 2:
                    result[1] = i + 1
                    return result
        
        # If unable to find two split points, return [-1, -1]
        return [-1, -1]

# Driver Code
if __name__ == "__main__":
    testCases = int(input().strip())

    for _ in range(testCases):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        result = ob.findSplit(arr)

        if result[0] == -1 and result[1] == -1:
            print("false")
        else:
            print("true")
        print("~")
