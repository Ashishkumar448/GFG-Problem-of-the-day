class Solution:
    def sumClosest(self, arr, target):
        # Sort the array to enable two-pointer technique
        arr.sort()
        n = len(arr)
        
        # Edge case: if less than two elements, return empty list
        if n < 2:
            return []
        
        closestSum = float('inf')
        maxAbsDifference = float('-inf')
        result = []
        
        left, right = 0, n - 1
        
        while left < right:
            sum_ = arr[left] + arr[right]
            
            # Update closest sum and result pair if closer to target
            if abs(sum_ - target) < abs(closestSum - target) or \
               (abs(sum_ - target) == abs(closestSum - target) and 
                abs(arr[right] - arr[left]) > maxAbsDifference):
                
                closestSum = sum_
                maxAbsDifference = abs(arr[right] - arr[left])
                result = [arr[left], arr[right]]
            
            # Move pointers based on sum comparison with target
            if sum_ < target:
                left += 1
            else:
                right -= 1
        
        return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input().strip())

        obj = Solution()
        res = obj.sumClosest(arr, target)

        if not res:
            print("[]")
        else:
            print(" ".join(map(str, res)))
        print("~")
