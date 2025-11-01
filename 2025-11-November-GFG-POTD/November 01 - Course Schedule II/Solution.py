from collections import deque, defaultdict

class Solution:
    def findOrder(self, n: int, prerequisites: list[list[int]]) -> list[int]:
        adj = defaultdict(list)
        indegree = [0] * n

        # build graph
        for course, prereq in prerequisites:
            adj[prereq].append(course)
            indegree[course] += 1

        q = deque([i for i in range(n) if indegree[i] == 0])
        order = []

        while q:
            curr = q.popleft()
            order.append(curr)

            for next_course in adj[curr]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)

        return order if len(order) == n else []
