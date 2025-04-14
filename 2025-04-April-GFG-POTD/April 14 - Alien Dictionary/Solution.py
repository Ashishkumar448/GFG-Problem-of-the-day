from collections import defaultdict, deque

class Solution:
    def findOrder(self, words):
        graph = defaultdict(list)
        indegree = defaultdict(int)

        # Step 1: Initialize nodes
        for word in words:
            for c in word:
                if c not in graph:
                    graph[c] = []
                if c not in indegree:
                    indegree[c] = 0

        # Step 2: Build edges
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            min_len = min(len(w1), len(w2))
            found = False
            for j in range(min_len):
                if w1[j] != w2[j]:
                    graph[w1[j]].append(w2[j])
                    indegree[w2[j]] += 1
                    found = True
                    break
            if not found and len(w1) > len(w2):
                return ""

        # Step 3: Topological Sort
        queue = deque([c for c in indegree if indegree[c] == 0])
        result = []

        while queue:
            curr = queue.popleft()
            result.append(curr)
            for neighbor in graph[curr]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return "".join(result) if len(result) == len(graph) else ""
