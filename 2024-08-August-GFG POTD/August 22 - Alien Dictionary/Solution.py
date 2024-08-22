from collections import deque, defaultdict

class Solution:
    def findOrder(self, dict, N, K):
        # Create a graph with K nodes (one for each character)
        adj = defaultdict(list)
        
        # Build the graph
        for i in range(N - 1):
            word1 = dict[i]
            word2 = dict[i + 1]
            min_length = min(len(word1), len(word2))
            for j in range(min_length):
                if word1[j] != word2[j]:
                    adj[ord(word1[j]) - ord('a')].append(ord(word2[j]) - ord('a'))
                    break
        
        # Perform topological sort using BFS (Kahn's Algorithm)
        indegree = [0] * K
        for i in range(K):
            for it in adj[i]:
                indegree[it] += 1
        
        q = deque()
        for i in range(K):
            if indegree[i] == 0:
                q.append(i)
        
        order = []
        while q:
            node = q.popleft()
            order.append(chr(node + ord('a')))
            for it in adj[node]:
                indegree[it] -= 1
                if indegree[it] == 0:
                    q.append(it)
        
        # If the order contains all K characters, return it
        if len(order) == K:
            return ''.join(order)
        else:
            return ""  # Return empty string if not all characters are included

# Driver code
if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        n, k = map(int, input().split())
        
        words = [input().strip() for _ in range(n)]
        
        ob = Solution()
        order = ob.findOrder(words, n, k)
        if len(order) == 0:
            print(0)
            continue
        if len(order) != k:
            print("INCOMPLETE")
            break
        
        temp = [words[i] for i in range(n)]
        
        temp.sort(key=lambda a: [order.index(c) for c in a])
        
        flag = 1
        for i in range(n):
            if words[i] != temp[i]:
                flag = 0
                break
        
        print(flag)
