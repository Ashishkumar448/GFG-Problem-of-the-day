class Solution:
    class TrieNode:
        def __init__(self):
            self.child = [None, None]
            self.count = 0

    def insert(self, root, num):
        for i in range(15, -1, -1):
            bit = (num >> i) & 1
            if root.child[bit] is None:
                root.child[bit] = self.TrieNode()
            root = root.child[bit]
            root.count += 1

    def countLessThanK(self, root, num, k):
        res = 0
        for i in range(15, -1, -1):
            if root is None:
                break
            bitNum = (num >> i) & 1
            bitK = (k >> i) & 1

            if bitK == 1:
                if root.child[bitNum] is not None:
                    res += root.child[bitNum].count
                root = root.child[1 - bitNum]
            else:
                root = root.child[bitNum]
        return res

    def cntPairs(self, arr, k):
        root = self.TrieNode()
        ans = 0
        for num in arr:
            ans += self.countLessThanK(root, num, k)
            self.insert(root, num)
        return ans
