class Solution:
    def findPeakGrid(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        low, high = 0, m - 1
        
        while low <= high:
            mid = (low + high) // 2
            
            # Find row index of maximum element in mid column
            max_row = 0
            for i in range(n):
                if mat[i][mid] > mat[max_row][mid]:
                    max_row = i
            
            left = mat[max_row][mid - 1] if mid - 1 >= 0 else float('-inf')
            right = mat[max_row][mid + 1] if mid + 1 < m else float('-inf')
            
            # Check peak condition
            if mat[max_row][mid] >= left and mat[max_row][mid] >= right:
                return [max_row, mid]
            elif left > mat[max_row][mid]:
                high = mid - 1
            else:
                low = mid + 1
        
        return []  # Peak always exists
