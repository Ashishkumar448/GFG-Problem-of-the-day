from collections import deque

class Solution:
    def orangesRotting(self, mat):
        n, m = len(mat), len(mat[0])
        queue = deque()
        freshOranges = 0

        # Step 1: Store all rotten oranges' positions and count fresh oranges
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2:
                    queue.append((i, j))
                elif mat[i][j] == 1:
                    freshOranges += 1

        # If there are no fresh oranges, return 0
        if freshOranges == 0:
            return 0

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        time = 0

        # Step 2: BFS traversal
        while queue:
            size = len(queue)
            rotted = False

            for _ in range(size):
                x, y = queue.popleft()

                for dx, dy in directions:
                    nx, ny = x + dx, y + dy

                    if 0 <= nx < n and 0 <= ny < m and mat[nx][ny] == 1:
                        mat[nx][ny] = 2
                        queue.append((nx, ny))
                        freshOranges -= 1
                        rotted = True

            if rotted:
                time += 1

        # If any fresh orange is left, return -1
        return time if freshOranges == 0 else -1

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        mat = [list(map(int, input().split())) for _ in range(n)]
        obj = Solution()
        print(obj.orangesRotting(mat))
        print("~")
