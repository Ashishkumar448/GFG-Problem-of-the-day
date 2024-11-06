class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def treePathsSum(self, root):
        if root is None:
            return 0

        total_sum = 0
        stack = [(root, root.data)]

        while stack:
            node, current_sum = stack.pop()

            if node.left is None and node.right is None:
                total_sum += current_sum

            if node.right:
                stack.append((node.right, current_sum * 10 + node.right.data))
            if node.left:
                stack.append((node.left, current_sum * 10 + node.left.data))

        return total_sum

def build_tree(s):
    if not s or s[0] == 'N':
        return None

    values = s.split()
    root = Node(int(values[0]))
    queue = [root]
    i = 1

    while queue and i < len(values):
        current = queue.pop(0)

        if values[i] != 'N':
            current.left = Node(int(values[i]))
            queue.append(current.left)
        i += 1

        if i >= len(values):
            break

        if values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        root = build_tree(s)
        ob = Solution()
        print(ob.treePathsSum(root))
