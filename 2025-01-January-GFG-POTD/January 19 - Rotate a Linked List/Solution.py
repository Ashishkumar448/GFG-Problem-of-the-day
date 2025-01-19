class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def rotate(self, head, k):
        # Edge case: If the list is empty or has only one node or no rotation is needed
        if not head or not head.next or k == 0:
            return head

        # Step 1: Calculate the length of the linked list
        current = head
        length = 1
        while current.next:
            current = current.next
            length += 1

        # Step 2: Calculate the effective number of rotations
        k = k % length
        if k == 0:
            return head

        # Step 3: Traverse to the (k-th) node
        current = head
        for _ in range(1, k):
            current = current.next

        # Step 4: The new head is the next node after the (k-th) node
        new_head = current.next

        # Step 5: Break the list into two parts and reconnect
        current.next = None

        # Step 6: Find the tail of the second part and connect it to the original head
        tail = new_head
        while tail.next:
            tail = tail.next
        tail.next = head

        return new_head


# Helper function to print the linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        if len(arr) > 0:
            head = Node(arr[0])
            tail = head
            for val in arr[1:]:
                tail.next = Node(val)
                tail = tail.next
        else:
            head = None

        k = int(input())
        ob = Solution()
        head = ob.rotate(head, k)
        printList(head)
