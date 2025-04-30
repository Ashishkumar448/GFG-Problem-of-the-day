class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def makeLoop(head, tail, x):
    if x == 0:
        return
    curr = head
    for _ in range(1, x):
        curr = curr.next
    tail.next = curr

def countLoopLength(nodeInLoop):
    count = 1
    current = nodeInLoop
    while current.next != nodeInLoop:
        current = current.next
        count += 1
    return count

def countNodesinLoop(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return countLoopLength(slow)
    return 0

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())

        head = Node(arr[0])
        tail = head
        for value in arr[1:]:
            tail.next = Node(value)
            tail = tail.next

        makeLoop(head, tail, k)
        print(countNodesinLoop(head))
        print("~")
