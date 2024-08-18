class Solution:
    def canSplit(self, arr):
        total_sum = sum(arr)
        
        # If the total sum is odd, we can't split it into two equal parts
        if total_sum % 2 != 0:
            return False
        
        half_sum = total_sum // 2
        running_sum = 0
        
        # Iterate through the array and check if we can find a split
        for num in arr:
            running_sum += num
            if running_sum == half_sum:
                return True
        
        return False

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        
        obj = Solution()
        res = obj.canSplit(arr)
        print(res)
