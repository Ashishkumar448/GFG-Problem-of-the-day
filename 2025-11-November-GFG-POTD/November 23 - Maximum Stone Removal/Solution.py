class Solution:
    class DSU:
        def __init__(self, n):
            self.parent = list(range(n))
            self.rank = [0] * n

        def find(self, x):
            if self.parent[x] != x:
                self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

        def union(self, x, y):
            px = self.find(x)
            py = self.find(y)

            if px == py:
                return

            if self.rank[px] < self.rank[py]:
                self.parent[px] = py
            elif self.rank[px] > self.rank[py]:
                self.parent[py] = px
            else:
                self.parent[py] = px
                self.rank[px] += 1

    def maxRemove(self, stones):
        n = len(stones)
        OFFSET = 10001
        dsu = self.DSU(20005)
        uniqueParents = set()

        # union rows and columns
        for x, y in stones:
            dsu.union(x, y + OFFSET)

        # count unique connected components
        for x, y in stones:
            uniqueParents.add(dsu.find(x))

        return n - len(uniqueParents)
