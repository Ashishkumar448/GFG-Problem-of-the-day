class TrieNode:
    def __init__(self):
        self.children = [None] * 26  # For a-z
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str):
        node = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        node = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                return False
            node = node.children[idx]
        return node.is_end_of_word

    def isPrefix(self, prefix: str) -> bool:
        node = self.root
        for ch in prefix:
            idx = ord(ch) - ord('a')
            if not node.children[idx]:
                return False
            node = node.children[idx]
        return True


# Driver code
t = int(input())
for _ in range(t):
    q = int(input())
    trie = Trie()
    results = []

    for _ in range(q):
        parts = input().split()
        typ, s = int(parts[0]), parts[1]
        if typ == 1:
            trie.insert(s)
        elif typ == 2:
            results.append(trie.search(s))
        elif typ == 3:
            results.append(trie.isPrefix(s))

    print(" ".join(map(str, results)))
    print("~")
