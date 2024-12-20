# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        r, c = map(int, input().split())
        mat = [list(map(int, input().split())) for _ in range(r)]
        
        def spirallyTraverse(mat, r, c):
            result = []
            top, bottom, left, right = 0, r - 1, 0, c - 1

            while top <= bottom and left <= right:
                # Traverse from left to right
                for i in range(left, right + 1):
                    result.append(mat[top][i])
                top += 1

                # Traverse from top to bottom
                for i in range(top, bottom + 1):
                    result.append(mat[i][right])
                right -= 1

                # Traverse from right to left, if rows are remaining
                if top <= bottom:
                    for i in range(right, left - 1, -1):
                        result.append(mat[bottom][i])
                    bottom -= 1

                # Traverse from bottom to top, if columns are remaining
                if left <= right:
                    for i in range(bottom, top - 1, -1):
                        result.append(mat[i][left])
                    left += 1

            return result
        
        ans = spirallyTraverse(mat, r, c)
        print(" ".join(map(str, ans)))
