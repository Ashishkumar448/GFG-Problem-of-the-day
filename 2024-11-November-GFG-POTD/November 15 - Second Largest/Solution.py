class Solution:
    def getSecondLargest(self, arr):
        if len(arr) < 2:
            return -1  # Return -1 if there are not enough elements for a second largest
        
        largest = float('-inf')
        second_largest = float('-inf')

        for num in arr:
            if num > largest:
                second_largest = largest  # update second largest before updating largest
                largest = num
            elif num > second_largest and num < largest:
                second_largest = num  # update second largest if num is less than largest but greater than second_largest

        return second_largest if second_largest != float('-inf') else -1


if __name__ == "__main__":
    t = int(input().strip())
    
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getSecondLargest(arr)
        print(ans)
        print("~")
