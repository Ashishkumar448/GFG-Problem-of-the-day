class Solution:
    def ValidCorner(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        colPairs = [[False] * m for _ in range(m)]

        for i in range(n):
            for col1 in range(m):
                if mat[i][col1] == 1:
                    for col2 in range(col1 + 1, m):
                        if mat[i][col2] == 1:
                            if colPairs[col1][col2]:
                                return True
                            colPairs[col1][col2] = True
        return False
