class Solution:
    def celebrity(self, mat):
        n = len(mat)
        candidate = 0

        # Step 1: Find a potential celebrity
        for i in range(1, n):
            if mat[candidate][i] == 1:
                # candidate knows i → candidate can't be celebrity
                candidate = i
            # else i cannot be celebrity

        # Step 2: Verify candidate
        for i in range(n):
            if i != candidate:
                # Candidate should not know i, and everyone should know candidate
                if mat[candidate][i] == 1 or mat[i][candidate] == 0:
                    return -1

        return candidate
