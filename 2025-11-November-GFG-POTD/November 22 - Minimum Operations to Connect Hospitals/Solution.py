class Solution:
    def find(self, x, parent):
        if parent[x] != x:
            parent[x] = self.find(parent[x], parent)
        return parent[x]

    def union(self, a, b, parent, rank):
        pa = self.find(a, parent)
        pb = self.find(b, parent)
        if pa == pb:
            return

        if rank[pa] < rank[pb]:
            parent[pa] = pb
        elif rank[pb] < rank[pa]:
            parent[pb] = pa
        else:
            parent[pb] = pa
            rank[pa] += 1

    def minConnect(self, V, edges):
        # Not enough edges
        if len(edges) < V - 1:
            return -1

        parent = [i for i in range(V)]
        rank = [0] * V

        # Union edges
        for u, v in edges:
            self.union(u, v, parent, rank)

        # Count components
        components = sum(1 for i in range(V) if parent[i] == i)

        return components - 1
