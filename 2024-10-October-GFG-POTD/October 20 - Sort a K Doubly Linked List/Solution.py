import heapq

class DLLNode:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None

def push(tail, new_data):
    new_node = DLLNode(new_data)
    new_node.next = None
    new_node.prev = tail

    if tail:
        tail.next = new_node

def print_list(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

class Solution:
    def sortAKSortedDLL(self, head, k):
        if not head:
            return None

        # Min heap to store DLLNodes based on their data
        min_heap = []
        current = head

        # Insert the first k+1 items into the min heap
        for _ in range(k + 1):
            if current:
                heapq.heappush(min_heap, (current.data, current))
                current = current.next

        new_head = None
        last = None

        # Process the heap and form the sorted doubly linked list
        while min_heap:
            # Extract the node with the smallest value
            _, min_node = heapq.heappop(min_heap)

            # Set the first node as the new head
            if not new_head:
                new_head = min_node
                new_head.prev = None
                last = new_head
            else:
                last.next = min_node
                min_node.prev = last
                last = min_node

            # Add the next node from the list to the heap
            if current:
                heapq.heappush(min_heap, (current.data, current))
                current = current.next

        # The last node's next should be null
        last.next = None

        return new_head

# Driver code
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())

        head = DLLNode(arr[0])
        tail = head

        for i in range(1, len(arr)):
            push(tail, arr[i])
            tail = tail.next

        obj = Solution()
        sorted_head = obj.sortAKSortedDLL(head, k)
        print_list(sorted_head)
