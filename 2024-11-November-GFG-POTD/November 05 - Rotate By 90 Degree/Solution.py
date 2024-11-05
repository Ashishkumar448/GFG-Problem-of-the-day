def rotate(matrix):
    n = len(matrix)

    # Step 1: Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            # Swap element at (i, j) with element at (j, i)
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for i in range(n):
        matrix[i].reverse()

def printMatrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        matrix = [list(map(int, input().split())) for _ in range(n)]

        rotate(matrix)
        printMatrix(matrix)
        print("~")
