class Solution:
    def find(self, node, parent):
        if node == parent[node]:
            return node
        parent[node] = self.find(parent[node], parent)  # Path compression
        return parent[node]

    def isCycle(self, V, edges):
        parent = [i for i in range(V)]

        for u, v in edges:
            parentU = self.find(u, parent)
            parentV = self.find(v, parent)

            if parentU == parentV:
                return True
            parent[parentU] = parentV

        return False


# Example usage
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V, E = map(int, input().split())
        edges = [list(map(int, input().split())) for _ in range(E)]

        obj = Solution()
        ans = obj.isCycle(V, edges)
        print("true" if ans else "false")
        print("~")
