class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        if not head or k <= 1:
            return head

        curr = head
        new_head = None
        tail = None

        while curr:
            group_prev = None
            group_curr = curr
            count = 0

            # Reverse the group
            while curr and count < k:
                next_node = curr.next
                curr.next = group_prev
                group_prev = curr
                curr = next_node
                count += 1

            # Update the new head for the first group
            if not new_head:
                new_head = group_prev

            # Connect previous group to the current reversed group
            if tail:
                tail.next = group_prev

            # Move the tail pointer to the current group's tail
            tail = group_curr

        return new_head

# Helper functions to test the code
def print_list(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()

# Example usage
if __name__ == "__main__":
    # Input handling and driver code can be added here.
    pass
