class Node:
    def __init__(self, key):
        self.data = key
        self.next = None

class SortLL:
    head = None

    @staticmethod
    def add_to_the_last(node):
        if SortLL.head is None:
            SortLL.head = node
        else:
            temp = SortLL.head
            while temp.next:
                temp = temp.next
            temp.next = node

    @staticmethod
    def print_list(head):
        while head:
            print(head.data, end=" ")
            head = head.next
        print()

class GfG:
    @staticmethod
    def quick_sort(node):
        if node is None or node.next is None:
            return node
        
        left, pivot, right = GfG.partition(node)
        left = GfG.quick_sort(left)
        right = GfG.quick_sort(right)
        
        return GfG.concatenate(left, pivot, right)

    @staticmethod
    def partition(node):
        pivot = node
        left_dummy = Node(0)
        right_dummy = Node(0)
        left, right = left_dummy, right_dummy
        current = node.next
        
        while current:
            if current.data < pivot.data:
                left.next = current
                left = left.next
            else:
                right.next = current
                right = right.next
            current = current.next
        
        left.next = None
        right.next = None
        
        return left_dummy.next, pivot, right_dummy.next

    @staticmethod
    def concatenate(left, pivot, right):
        head = pivot
        if left:
            head = left
            temp = left
            while temp.next:
                temp = temp.next
            temp.next = pivot
        
        pivot.next = right
        return head

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        elements = list(map(int, input().split()))
        SortLL.head = Node(elements[0])
        SortLL.add_to_the_last(SortLL.head)
        for elem in elements[1:]:
            SortLL.add_to_the_last(Node(elem))
        
        gfg = GfG()
        sorted_head = gfg.quick_sort(SortLL.head)
        SortLL.print_list(sorted_head)
        print("~")
