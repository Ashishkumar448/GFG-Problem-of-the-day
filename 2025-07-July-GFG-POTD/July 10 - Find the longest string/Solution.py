from collections import deque, defaultdict

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False
        self.word = ""

class Solution:
    def longestString(self, arr):
        root = TrieNode()

        # Insert all words into the Trie
        for word in arr:
            curr = root
            for ch in word:
                if ch not in curr.children:
                    curr.children[ch] = TrieNode()
                curr = curr.children[ch]
            curr.is_end = True
            curr.word = word

        # BFS to find the longest valid string
        result = ""
        queue = deque([root])

        while queue:
            curr = queue.popleft()

            for ch in sorted(curr.children.keys()):
                next_node = curr.children[ch]
                if next_node.is_end:
                    queue.append(next_node)
                    if (len(next_node.word) > len(result) or
                        (len(next_node.word) == len(result) and next_node.word < result)):
                        result = next_node.word

        return result
