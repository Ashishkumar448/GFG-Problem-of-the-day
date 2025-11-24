class Solution:

    # DSU for Kruskal
    class DSU:
        def __init__(self, n):
            self.p = list(range(n))
            self.r = [0] * n

        def find(self, x):
            if self.p[x] != x:
                self.p[x] = self.find(self.p[x])
            return self.p[x]

        def union(self, a, b):
            a, b = self.find(a), self.find(b)
            if a == b:
                return False
            if self.r[a] < self.r[b]:
                self.p[a] = b
            elif self.r[b] < self.r[a]:
                self.p[b] = a
            else:
                self.p[b] = a
                self.r[a] += 1
            return True

    # Build MST skipping exactly one edge
    def buildMST(self, V, edges, su, sv, sw):
        d = self.DSU(V)
        total = 0
        used = 0

        for u, v, w in edges:
            if u == su and v == sv and w == sw:
                continue
            if d.union(u, v):
                total += w
                used += 1

        return total if used == V - 1 else float('inf')

    def secondMST(self, V, edges):

        edges.sort(key=lambda x: x[2])

        mstWeight = self.buildMST(V, edges, -1, -1, -1)
        if mstWeight == float('inf'):
            return -1

        secondBest = float('inf')

        for u, v, w in edges:
            w2 = self.buildMST(V, edges, u, v, w)
            if w2 > mstWeight:
                secondBest = min(secondBest, w2)

        return -1 if secondBest == float('inf') else secondBest
