# { Driver Code Starts
# Initial Template for Python

class Solution:
    # Function to rotate matrix anticlockwise by 90 degrees.
    def rotateby90(self, mat):
        n = len(mat)

        # Step 1: Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

        # Step 2: Reverse each column
        for j in range(n):
            for i in range(n // 2):
                mat[i][j], mat[n - i - 1][j] = mat[n - i - 1][j], mat[i][j]


# { Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        matrix = []
        for i in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ob.rotateby90(matrix)
        for row in matrix:
            print(" ".join(map(str, row)))
        print("~")
