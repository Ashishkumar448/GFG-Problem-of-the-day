def spirallyTraverse(matrix):
    result = []
    if not matrix:
        return result

    startRow, startCol = 0, 0
    endRow, endCol = len(matrix) - 1, len(matrix[0]) - 1

    while startRow <= endRow and startCol <= endCol:
        # Top row
        for j in range(startCol, endCol + 1):
            result.append(matrix[startRow][j])
        startRow += 1

        # Right column
        for i in range(startRow, endRow + 1):
            result.append(matrix[i][endCol])
        endCol -= 1

        # Bottom row
        if startRow <= endRow:
            for j in range(endCol, startCol - 1, -1):
                result.append(matrix[endRow][j])
            endRow -= 1

        # Left column
        if startCol <= endCol:
            for i in range(endRow, startRow - 1, -1):
                result.append(matrix[i][startCol])
            startCol += 1

    return result

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        r, c = map(int, input().split())
        matrix = []
        for _ in range(r):
            matrix.append(list(map(int, input().split())))
        result = spirallyTraverse(matrix)
        print(" ".join(map(str, result)))
