class Solution:
    def celebrity(self, mat):
        n = len(mat)
        candidate = 0

        # Step 1: Find the candidate
        for i in range(1, n):
            if mat[candidate][i] == 1:
                candidate = i

        # Step 2: Verify the candidate
        for i in range(n):
            if i != candidate and (mat[candidate][i] == 1 or mat[i][candidate] == 0):
                return -1

        return candidate


# { 
# Driver Code Starts
# Main function to handle input and output
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        M = []
        for _ in range(n):
            M.append(list(map(int, input().split())))

        ob = Solution()
        print(ob.celebrity(M))

# } Driver Code Ends