class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def f(self, root):
        if not root:
            return (0, 0)
        
        left_height, left_diameter = self.f(root.left)
        right_height, right_diameter = self.f(root.right)

        height = 1 + max(left_height, right_height)
        diameter = max(left_diameter, right_diameter, left_height + right_height)

        return (height, diameter)

    def diameter(self, root):
        return self.f(root)[1]

# Function to build tree from input string
def buildTree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    q = [root]
    
    i = 1
    while q and i < len(ip):
        currNode = q.pop(0)

        leftVal = ip[i]
        if leftVal != "N":
            currNode.left = Node(int(leftVal))
            q.append(currNode.left)

        i += 1
        if i >= len(ip):
            break

        rightVal = ip[i]
        if rightVal != "N":
            currNode.right = Node(int(rightVal))
            q.append(currNode.right)

        i += 1

    return root

# Driver code
if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        s = input().strip()
        root = buildTree(s)
        sol = Solution()
        print(sol.diameter(root))
