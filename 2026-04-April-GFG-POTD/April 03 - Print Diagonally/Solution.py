class Solution:
    def diagView(self, mat):
        n = len(mat)
        res = []
        
        # Loop over all diagonals
        for d in range(2 * n - 1):
            
            # Row index
            row = 0 if d < n else d - n + 1
            
            # Column index
            col = d if d < n else n - 1
            
            # Traverse the diagonal
            while row < n and col >= 0:
                res.append(mat[row][col])
                row += 1
                col -= 1
        
        return res
