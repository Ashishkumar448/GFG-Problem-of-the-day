# Node class for linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Solution class containing the method to find the middle of the list
class Solution:
    def getMiddle(self, head):
        if head is None:
            return -1  # Return -1 if the list is empty

        slow = head
        fast = head

        # Move slow by 1 step and fast by 2 steps until fast reaches the end
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        # slow will be at the middle of the list
        return slow.data

# Function to print the linked list
def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        values = list(map(int, input().strip().split()))
        head = Node(values[0])
        tail = head
        for value in values[1:]:
            tail.next = Node(value)
            tail = tail.next

        solution = Solution()
        ans = solution.getMiddle(head)
        print(ans)
        # printList(head) # Uncomment to print the list
