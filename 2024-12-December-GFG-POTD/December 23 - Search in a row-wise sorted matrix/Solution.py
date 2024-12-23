class Solution:
    # Function to search a given number in row-column sorted matrix.
    def searchRowMatrix(self, mat, x):
        for row in mat:
            # Apply binary search on each row
            if self.binarySearch(row, x):
                return True
        return False

    def binarySearch(self, row, x):
        left, right = 0, len(row) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if row[mid] == x:
                return True
            elif row[mid] < x:
                left = mid + 1
            else:
                right = mid - 1
        return False

# Driver Code
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        rows, columns = map(int, input().split())
        matrix = [list(map(int, input().split())) for _ in range(rows)]
        target = int(input())

        solution = Solution()
        if solution.searchRowMatrix(matrix, target):
            print("true")
        else:
            print("false")

        print("~")
        t -= 1
