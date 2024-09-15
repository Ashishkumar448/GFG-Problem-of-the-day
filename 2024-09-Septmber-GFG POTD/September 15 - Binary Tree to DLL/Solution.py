class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BT_To_DLL:
    def buildTree(self, s):
        if len(s) == 0 or s[0] == 'N':
            return None

        ip = s.split()
        root = Node(int(ip[0]))
        queue = []
        queue.append(root)

        i = 1
        while len(queue) > 0 and i < len(ip):
            currNode = queue.pop(0)
            currVal = ip[i]

            if currVal != "N":
                currNode.left = Node(int(currVal))
                queue.append(currNode.left)

            i += 1
            if i >= len(ip):
                break
            currVal = ip[i]

            if currVal != "N":
                currNode.right = Node(int(currVal))
                queue.append(currNode.right)

            i += 1

        return root

    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        print(node.data, end=" ")
        self.inorder(node.right)

    def printList(self, head):
        prev = head
        while head is not None:
            print(head.data, end=" ")
            prev = head
            head = head.right
        print()
        while prev is not None:
            print(prev.data, end=" ")
            prev = prev.left
        print()

class Solution:
    def __init__(self):
        self.prev = None
        self.head = None

    def bToDLL(self, root):
        if root is None:
            return None

        # Recursively convert the left subtree
        self.bToDLL(root.left)

        # Handle the current node
        if self.prev is None:
            self.head = root
        else:
            self.prev.right = root
            root.left = self.prev

        # Move prev to the current node
        self.prev = root

        # Recursively convert the right subtree
        self.bToDLL(root.right)

        return self.head

if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        s = input()
        tree = BT_To_DLL()
        root = tree.buildTree(s)
        sol = Solution()
        ans = sol.bToDLL(root)
        tree.printList(ans)
