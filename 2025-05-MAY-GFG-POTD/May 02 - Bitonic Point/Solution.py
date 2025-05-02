class Solution:
    def findMaximum(self, arr):
        low, high = 0, len(arr) - 1
        
        while low <= high:
            mid = (low + high) // 2
            
            if 0 < mid < len(arr) - 1:
                if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
                    return arr[mid]
                elif arr[mid] > arr[mid - 1]:
                    low = mid + 1
                else:
                    high = mid - 1
            elif mid == 0:
                return max(arr[0], arr[1])
            elif mid == len(arr) - 1:
                return max(arr[-1], arr[-2])
        
        return -1

# Driver code
t = int(input())
for _ in range(t):
    arr = list(map(int, input().strip().split()))
    sol = Solution()
    print(sol.findMaximum(arr))
    print("~")
