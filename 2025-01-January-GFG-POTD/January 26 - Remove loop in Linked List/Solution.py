class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeLoop(head):
    if head is None or head.next is None:
        return

    slow, fast = head, head

    # Detecting the loop using Floyd's Cycle Detection Algorithm
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        # If slow and fast meet, there is a loop
        if slow == fast:
            break

    # If no loop is found, return
    if fast is None or fast.next is None:
        return

    # Find the start of the loop
    slow = head
    if slow != fast:
        while slow.next != fast.next:
            slow = slow.next
            fast = fast.next
    else:
        # Special case: when the loop starts at the head
        while fast.next != slow:
            fast = fast.next

    # Break the loop
    fast.next = None

# Helper function to create a new node
def newNode(data):
    return Node(data)

# Helper function to create a loop in the linked list
def makeLoop(head, x):
    if x == 0:
        return

    curr = head
    last = head

    currentPosition = 1
    while currentPosition < x:
        curr = curr.next
        currentPosition += 1

    while last.next:
        last = last.next
    last.next = curr

# Helper function to detect if a loop exists
def detectLoop(head):
    hare, tortoise = head.next, head
    while hare != tortoise:
        if hare is None or hare.next is None:
            return False
        hare = hare.next.next
        tortoise = tortoise.next
    return True

# Main function for testing
if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    pos = int(input())

    head = newNode(arr[0])
    tail = head
    for i in range(1, n):
        tail.next = newNode(arr[i])
        tail = tail.next

    makeLoop(head, pos)
    removeLoop(head)

    if detectLoop(head):
        print("false")
    else:
        print("true")
