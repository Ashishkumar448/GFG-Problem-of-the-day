class Solution:
    def matSearch(self, mat, x):
        n = len(mat)
        m = len(mat[0])
        
        # Start from the top-right corner
        row, col = 0, m - 1
        
        while row < n and col >= 0:
            if mat[row][col] == x:
                return True  # Found the element
            elif mat[row][col] > x:
                col -= 1  # Move left
            else:
                row += 1  # Move down
        
        return False  # Element not found


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        mat = [list(map(int, input().split())) for _ in range(n)]
        x = int(input())
        
        sol = Solution()
        if sol.matSearch(mat, x):
            print("true")
        else:
            print("false")
        
        print("~")
