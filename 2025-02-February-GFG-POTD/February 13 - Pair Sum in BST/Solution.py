class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def in_order_traversal(root, nodes):
    if not root:
        return
    in_order_traversal(root.left, nodes)
    nodes.append(root.data)
    in_order_traversal(root.right, nodes)

def find_target(root, target):
    nodes = []
    in_order_traversal(root, nodes)
    left, right = 0, len(nodes) - 1
    while left < right:
        total = nodes[left] + nodes[right]
        if total == target:
            return True
        elif total < target:
            left += 1
        else:
            right -= 1
    return False
