class Solution:
    def kthSmallest(self, mat, k):
        n = len(mat)
        
        low = mat[0][0]
        high = mat[n - 1][n - 1]
        
        while low < high:
            mid = low + (high - low) // 2
            
            if self.countLessEqual(mat, mid) < k:
                low = mid + 1
            else:
                high = mid
        
        return low
    
    def countLessEqual(self, mat, x):
        n = len(mat)
        count = 0
        row = n - 1
        col = 0
        
        while row >= 0 and col < n:
            if mat[row][col] <= x:
                count += row + 1
                col += 1
            else:
                row -= 1
        
        return count
