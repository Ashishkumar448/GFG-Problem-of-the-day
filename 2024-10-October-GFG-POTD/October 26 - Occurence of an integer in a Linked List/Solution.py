class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    @staticmethod
    def count(head, key):
        count = 0
        current = head
        
        # Traverse the linked list
        while current:
            # Check if the current node's data is equal to the key
            if current.data == key:
                count += 1
            current = current.next
        
        return count

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next

        key = int(input())
        print(Solution.count(head, key))
        print("~")
