import heapq

class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

class Solution:
    def mergeKLists(self, arr):
        minHeap = []

        # Add all the head nodes to the heap
        for head in arr:
            if head:
                heapq.heappush(minHeap, (head.data, head))

        # Dummy node for merged list
        dummy = Node(0)
        current = dummy

        while minHeap:
            _, smallestNode = heapq.heappop(minHeap)

            current.next = smallestNode
            current = current.next

            if smallestNode.next:
                heapq.heappush(minHeap, (smallestNode.next.data, smallestNode.next))

        return dummy.next

# Function to print the linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()

# Driver Code
if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        lists = []

        for _ in range(n):
            values = list(map(int, input().split()))
            head = None
            tail = None

            for val in values:
                newNode = Node(val)
                if head is None:
                    head = newNode
                    tail = head
                else:
                    tail.next = newNode
                    tail = tail.next

            lists.append(head)

        sol = Solution()
        result = sol.mergeKLists(lists)
        printList(result)
        print("~")
