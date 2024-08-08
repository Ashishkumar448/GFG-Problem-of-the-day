# Driver Code Starts
# Initial Template for Python 3

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# User function Template for python3
class Solution:
    def is_sum_tree(self, node):
        def is_sum_tree_helper(node):
            if node is None:
                return True, 0
            
            if node.left is None and node.right is None:
                return True, node.data
            
            left_is_sum_tree, left_sum = is_sum_tree_helper(node.left)
            right_is_sum_tree, right_sum = is_sum_tree_helper(node.right)
            
            current_sum = node.data
            
            if left_is_sum_tree and right_is_sum_tree and (current_sum == left_sum + right_sum):
                return True, current_sum + left_sum + right_sum
            else:
                return False, current_sum + left_sum + right_sum
        
        is_sum, total_sum = is_sum_tree_helper(node)
        return is_sum

# Driver Code Starts
def new_node(val):
    return Node(val)

def build_tree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.split()
    root = new_node(int(ip[0]))
    queue = [root]
    
    i = 1
    while queue and i < len(ip):
        curr_node = queue.pop(0)
        curr_val = ip[i]

        if curr_val != "N":
            curr_node.left = new_node(int(curr_val))
            queue.append(curr_node.left)
        
        i += 1
        if i >= len(ip):
            break
        curr_val = ip[i]
        
        if curr_val != "N":
            curr_node.right = new_node(int(curr_val))
            queue.append(curr_node.right)
        
        i += 1

    return root

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = build_tree(s)
        ob = Solution()
        if ob.is_sum_tree(root):
            print("true")
        else:
            print("false")

# Driver Code Ends
