class TrieNode:
    def __init__(self):
        self.child = [None, None]

class Solution:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, num):
        node = self.root
        for i in reversed(range(32)):
            bit = (num >> i) & 1
            if not node.child[bit]:
                node.child[bit] = TrieNode()
            node = node.child[bit]

    def findMaxXor(self, num):
        node = self.root
        maxXor = 0
        for i in reversed(range(32)):
            bit = (num >> i) & 1
            oppositeBit = bit ^ 1
            if node.child[oppositeBit]:
                maxXor |= (1 << i)
                node = node.child[oppositeBit]
            else:
                node = node.child[bit]
        return maxXor

    def maxXor(self, arr):
        for num in arr:
            self.insert(num)
        return max(self.findMaxXor(num) for num in arr)


# Driver code for testing
T = int(input())
for _ in range(T):
    n = int(input())
    arr = list(map(int, input().split()))
    sol = Solution()
    print(sol.maxXor(arr))
    print("~")
