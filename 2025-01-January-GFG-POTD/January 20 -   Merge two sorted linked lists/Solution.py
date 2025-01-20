class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()
    print("~")

def insert_sorted(head, data):
    new_node = Node(data)
    if not head or head.data >= data:
        new_node.next = head
        return new_node

    current = head
    while current.next and current.next.data < data:
        current = current.next
    new_node.next = current.next
    current.next = new_node

    return head

class Solution:
    def sorted_merge(self, head1, head2):
        dummy = Node(0)
        tail = dummy

        while head1 and head2:
            if head1.data <= head2.data:
                tail.next = head1
                head1 = head1.next
            else:
                tail.next = head2
                head2 = head2.next
            tail = tail.next

        if head1:
            tail.next = head1
        elif head2:
            tail.next = head2

        return dummy.next

# Driver code
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        head1, head2 = None, None

        # Reading input
        input1 = input().strip()
        input2 = input().strip()

        for elem in map(int, input1.split()):
            head1 = insert_sorted(head1, elem)

        for elem in map(int, input2.split()):
            head2 = insert_sorted(head2, elem)

        # Merging lists
        obj = Solution()
        merged_head = obj.sorted_merge(head1, head2)
        print_list(merged_head)
