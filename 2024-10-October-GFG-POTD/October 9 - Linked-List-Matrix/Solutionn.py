class Node:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.down = None

class Linked_list_2D_Matrix:
    def display(self, head):
        Dp = head
        while Dp:
            Rp = Dp
            while Rp:
                print(Rp.data, end=" ")
                if Rp.right:
                    print(Rp.right.data, end=" ")
                else:
                    print("null", end=" ")
                if Rp.down:
                    print(Rp.down.data, end=" ")
                else:
                    print("null", end=" ")
                Rp = Rp.right
            Dp = Dp.down
        print()

class Solution:
    def construct(self, arr):
        if not arr:
            return None
        
        n = len(arr)
        nodes = [[None for _ in range(n)] for _ in range(n)]

        # Create all nodes
        for i in range(n):
            for j in range(n):
                nodes[i][j] = Node(arr[i][j])

        # Set right and down pointers
        for i in range(n):
            for j in range(n):
                if j + 1 < n:
                    nodes[i][j].right = nodes[i][j + 1]
                if i + 1 < n:
                    nodes[i][j].down = nodes[i + 1][j]

        return nodes[0][0]

if __name__ == "__main__":
    t = int(input())
    ll2d = Linked_list_2D_Matrix()

    for _ in range(t):
        n = int(input())
        mat = [list(map(int, input().split())) for _ in range(n)]

        obj = Solution()
        head = obj.construct(mat)
        ll2d.display(head)
