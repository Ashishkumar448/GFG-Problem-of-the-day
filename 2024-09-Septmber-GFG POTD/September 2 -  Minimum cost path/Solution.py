import heapq

class Solution:
    # Function to return the minimum cost to reach the bottom-right cell from the top-left cell.
    def minimumCostPath(self, grid):
        n = len(grid)
        dist = [[float('inf')] * n for _ in range(n)]

        # Priority queue to store cells based on their cost.
        pq = [(grid[0][0], 0, 0)]
        dist[0][0] = grid[0][0]

        # Directions for moving up, down, left, right.
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        while pq:
            cost, x, y = heapq.heappop(pq)

            # If we reached the bottom-right corner, return the cost.
            if x == n - 1 and y == n - 1:
                return cost

            # Explore all four possible directions.
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]

                # Check if the new position is within the grid boundaries.
                if 0 <= nx < n and 0 <= ny < n:
                    newCost = cost + grid[nx][ny]

                    # Update the distance if a shorter path is found.
                    if newCost < dist[nx][ny]:
                        dist[nx][ny] = newCost
                        heapq.heappush(pq, (newCost, nx, ny))

        return dist[n - 1][n - 1]

# Driver code
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        grid = []
        for _ in range(n):
            grid.append(list(map(int, input().split())))
        obj = Solution()
        ans = obj.minimumCostPath(grid)
        print(ans)
