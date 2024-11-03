class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert(head, data):
    temp = Node(data)
    if head is None:
        head = temp
        return head
    else:
        t = head
        while t.next is not None:
            t = t.next
        t.next = temp
    return head

def print_list(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()

class Solution:
    def isLengthEven(self, head):
        current = head
        is_even = True

        # Traverse the list, toggling `is_even` each time we encounter a node
        while current is not None:
            is_even = not is_even
            current = current.next

        # If `is_even` is True, the list length is even; otherwise, it's odd
        return is_even

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        head = None
        data = list(map(int, input().split()))
        for val in data:
            head = insert(head, val)
        
        solution = Solution()
        f = solution.isLengthEven(head)
        print("true" if f else "false")
        print("~")  # delimiter similar to Java code
