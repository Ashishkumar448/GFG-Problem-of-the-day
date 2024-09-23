# Driver code
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        n = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr, n)
        print(ans[0], ans[1])
        t -= 1

# User function template for Python
class Solution:
    def findTwoElement(self, arr, n):
        # Expected sum and sum of squares of first n natural numbers
        S_n = n * (n + 1) // 2
        S_sq_n = n * (n + 1) * (2 * n + 1) // 6
        
        # Actual sum and sum of squares of the array
        S_arr = sum(arr)
        S_sq_arr = sum(x * x for x in arr)
        
        # Calculating the differences
        diff1 = S_n - S_arr          # X - Y
        diff2 = S_sq_n - S_sq_arr    # X^2 - Y^2 = (X - Y) * (X + Y)
        
        sumXY = diff2 // diff1       # X + Y
        
        # Solving for X and Y
        X = (diff1 + sumXY) // 2
        Y = sumXY - X
        
        return [Y, X]  # Return [repeating, missing]
