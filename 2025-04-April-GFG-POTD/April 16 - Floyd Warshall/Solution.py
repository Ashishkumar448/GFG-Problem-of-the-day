class Solution:
    def floydWarshall(self, dist):
        n = len(dist)
        inf = 10**8

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] < inf and dist[k][j] < inf and dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]


# Driver code for testing
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        matrix = [list(map(int, input().split())) for _ in range(n)]

        obj = Solution()
        obj.floydWarshall(matrix)

        for row in matrix:
            print(" ".join(map(str, row)))
        print("~")
