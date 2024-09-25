# Class to define a Node in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    # Function to check whether the list is palindrome.
    def isPalindrome(self, head):
        if not head or not head.next:
            return True  # A single node or empty list is always a palindrome

        # Step 1: Find the middle of the linked list.
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse the second half of the list.
        second_half = self.reverse(slow)

        # Step 3: Compare the first and second half of the list.
        first_half = head
        second_half_copy = second_half  # To restore the list later (optional)
        while second_half:
            if first_half.data != second_half.data:
                return False
            first_half = first_half.next
            second_half = second_half.next

        # Step 4: Optional - Restore the list to its original form by reversing the second half again.
        self.reverse(second_half_copy)

        return True

    # Helper function to reverse the linked list.
    def reverse(self, head):
        prev = None
        curr = head
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        return prev

# Utility function to insert a node at the end of the linked list
def insert(head, data):
    temp = Node(data)
    if head is None:
        return temp
    t = head
    while t.next:
        t = t.next
    t.next = temp
    return head

# Utility function to print the linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()

# Driver code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        head = None
        data_list = list(map(int, input().split()))  # Input the list of elements
        for data in data_list:
            head = insert(head, data)
        
        solution = Solution()
        if solution.isPalindrome(head):
            print("true")
        else:
            print("false")
