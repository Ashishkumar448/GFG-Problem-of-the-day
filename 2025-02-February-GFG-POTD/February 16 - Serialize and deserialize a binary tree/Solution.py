class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def serialize(self, root):
        def s(r, arr):
            if not r:
                arr.append(-1)
                return
            arr.append(r.data)
            s(r.left, arr)
            s(r.right, arr)

        result = []
        s(root, result)
        return result

    def deSerialize(self, data):
        def d(arr, idx):
            if idx[0] >= len(arr) or arr[idx[0]] == -1:
                idx[0] += 1
                return None
            node = Node(arr[idx[0]])
            idx[0] += 1
            node.left = d(arr, idx)
            node.right = d(arr, idx)
            return node

        return d(data, [0])
