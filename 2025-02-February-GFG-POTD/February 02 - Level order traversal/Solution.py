class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root):
        result = []
        
        if not root:
            return result  # Return empty if tree is empty
        
        queue = [root]  # Start with the root node

        while queue:
            level_size = len(queue)  # Number of nodes at the current level
            current_level = []

            for _ in range(level_size):
                current_node = queue.pop(0)  # Get and remove the front node
                current_level.append(current_node.data)  # Add current node's value to the level list

                # Add left child to the queue if it exists
                if current_node.left:
                    queue.append(current_node.left)
                # Add right child to the queue if it exists
                if current_node.right:
                    queue.append(current_node.right)

            result.append(current_level)  # Add current level list to the result
        
        return result  # Return the final result containing all levels

# Function to build tree from input string
def build_tree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    
    queue = [root]
    
    i = 1
    while queue and i < len(ip):
        curr_node = queue.pop(0)

        # Left child
        if ip[i] != "N":
            curr_node.left = Node(int(ip[i]))
            queue.append(curr_node.left)
        
        i += 1
        if i >= len(ip): break
        
        # Right child
        if ip[i] != "N":
            curr_node.right = Node(int(ip[i]))
            queue.append(curr_node.right)
        
        i += 1
    
    return root

# Main function to read input and execute level order traversal
if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        s = input().strip()
        root = build_tree(s)
        
        solution = Solution()
        res = solution.levelOrder(root)
        
        for level in res:
            print(" ".join(map(str, level)), end=" ")
        
        print("\n~")
