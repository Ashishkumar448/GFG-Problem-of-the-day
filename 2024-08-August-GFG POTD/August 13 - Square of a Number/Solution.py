class Solution:
    def floorSqrt(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        
        left, right, result = 1, n, 0
        
        while left <= right:
            mid = left + (right - left) // 2
            mid_squared = mid * mid
            
            if mid_squared == n:
                return mid
            if mid_squared < n:
                left = mid + 1
                result = mid
            else:
                right = mid - 1
        
        return result

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        a = int(input())
        obj = Solution()
        print(obj.floorSqrt(a))
        t -= 1

