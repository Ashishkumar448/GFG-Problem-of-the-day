# { Driver Code Starts
class Solution:
    # Function to search a given number in row-column sorted matrix.
    def searchMatrix(self, mat, x):
        rows = len(mat)
        cols = len(mat[0])

        i = 0  # Start from the first row
        j = cols - 1  # Start from the last column

        # Traverse the matrix
        while i < rows and j >= 0:
            if mat[i][j] == x:
                return True  # Target found
            elif mat[i][j] > x:
                j -= 1  # Move left
            else:
                i += 1  # Move down

        return False  # Target not found


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        rows, columns = map(int, input().split())

        matrix = []
        for _ in range(rows):
            row = list(map(int, input().split()))
            matrix.append(row)

        target = int(input())

        obj = Solution()
        if obj.searchMatrix(matrix, target):
            print("true")
        else:
            print("false")

        t -= 1
        print("~")
# } Driver Code Ends
