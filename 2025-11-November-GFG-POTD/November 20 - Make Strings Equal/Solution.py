class Solution:
    def minCost(self, s: str, t: str, transform, cost) -> int:
        n = len(s)
        INF = 10**15

        # Initialize 26x26 matrix
        dist = [[INF] * 26 for _ in range(26)]
        for i in range(26):
            dist[i][i] = 0

        # Fill edges
        for (x_char, y_char), c in zip(transform, cost):
            x = ord(x_char) - ord('a')
            y = ord(y_char) - ord('a')
            dist[x][y] = min(dist[x][y], c)

        # Floyd–Warshall
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if dist[i][k] < INF and dist[k][j] < INF:
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        total = 0

        # Match characters
        for a_char, b_char in zip(s, t):
            a = ord(a_char) - ord('a')
            b = ord(b_char) - ord('a')

            if a == b:
                continue

            best = min(
                dist[a][c] + dist[b][c]
                for c in range(26)
                if dist[a][c] < INF and dist[b][c] < INF
            )

            if best >= INF:
                return -1

            total += best

        return total
