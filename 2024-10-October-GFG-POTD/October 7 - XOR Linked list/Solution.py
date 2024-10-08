class Node:
    def __init__(self, data):
        self.data = data
        self.npx = None  # XOR of next and previous node

# Utility function to XOR two node references
def XOR(a, b):
    return a if not b else b if not a else a ^ b

# Function to insert a new node at the front of the XOR LinkedList
def insert(head, data):
    new_node = Node(data)
    new_node.npx = id(head)

    # If the list is not empty, adjust the previous head's npx
    if head:
        head.npx = XOR(new_node, head.npx)
    return new_node  # New node becomes the head

# Function to get the list in forward order
def get_list(head):
    result = []
    curr, prev, next_node = head, None, None

    while curr:
        result.append(curr.data)
        next_node = XOR(prev, curr.npx)
        prev, curr = curr, next_node

    return result

def main():
    t = int(input())

    for _ in range(t):
        head = None
        numbers = map(int, input().split())

        for number in numbers:
            head = insert(head, number)

        result = get_list(head)

        # Print list in forward order
        print(" ".join(map(str, result)))

        # Print list in reverse order
        print(" ".join(map(str, reversed(result))))

if __name__ == "__main__":
    main()
