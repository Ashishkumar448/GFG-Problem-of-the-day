class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def merge(self, root1: Node, root2: Node) -> list:
        list1, list2 = [], []
        
        # Perform inorder traversal on both BSTs to get sorted lists
        self.inorder(root1, list1)
        self.inorder(root2, list2)
        
        # Merge two sorted lists
        return self.merge_sorted_lists(list1, list2)

    # Helper function for inorder traversal
    def inorder(self, root, res):
        if root:
            self.inorder(root.left, res)
            res.append(root.data)
            self.inorder(root.right, res)

    # Helper function to merge two sorted lists
    def merge_sorted_lists(self, list1, list2):
        merged_list = []
        i, j = 0, 0
        
        while i < len(list1) and j < len(list2):
            if list1[i] < list2[j]:
                merged_list.append(list1[i])
                i += 1
            else:
                merged_list.append(list2[j])
                j += 1
        
        # Add any remaining elements
        while i < len(list1):
            merged_list.append(list1[i])
            i += 1
        
        while j < len(list2):
            merged_list.append(list2[j])
            j += 1
        
        return merged_list

# Helper function to build tree from string
def build_tree(data):
    if not data or data[0] == "N":
        return None

    values = list(map(str, data.split()))
    root = Node(int(values[0]))
    queue = [root]
    
    i = 1
    while i < len(values):
       

