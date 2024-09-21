# Python solution to clone a linked list with next and random pointer

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.random = None

class Solution:
    # Function to clone a linked list with next and random pointer.
    def copyList(self, head):
        if head is None:
            return None

        # Step 1: Create the copy of each node and insert it between the original nodes.
        curr = head
        while curr is not None:
            next_node = curr.next
            copy = Node(curr.data)
            curr.next = copy
            copy.next = next_node
            curr = next_node

        # Step 2: Update the random pointers for the copied nodes.
        curr = head
        while curr is not None:
            if curr.random is not None:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # Step 3: Separate the original list and the copied list.
        original = head
        copy_head = head.next
        copy = copy_head

        while original is not None:
            original.next = original.next.next
            if copy.next is not None:
                copy.next = copy.next.next
            original = original.next
            copy = copy.next

        return copy_head


# Utility function to add a node at the end of the list
def addToTheLast(head, node):
    if head is None:
        return node
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = node
        return head


# Validation function to check if the original and copied lists are identical
def validation(head, res):
    temp1 = head
    temp2 = res

    len1 = len2 = 0
    while temp1 is not None:
        len1 += 1
        temp1 = temp1.next
    while temp2 is not None:
        len2 += 1
        temp2 = temp2.next

    if len1 != len2:
        return False

    node_map = {}

    temp1 = head
    temp2 = res
    while temp1 is not None:
        if temp1 == temp2:
            return False
        if temp1.data != temp2.data:
            return False

        if (temp1.random is None and temp2.random is not None) or (temp1.random is not None and temp2.random is None):
            return False
        if temp1.random is not None and temp2.random is not None and temp1.random.data != temp2.random.data:
            return False
        node_map[temp1] = temp2
        temp1 = temp1.next
        temp2 = temp2.next

    temp1 = head
    temp2 = res
    while temp1 is not None:
        if temp1.random is not None and node_map[temp1.random] != temp2.random:
            return False
        temp1 = temp1.next
        temp2 = temp2.next

    return True


# Main function to run the test cases
if __name__ == '__main__':
    t = int(input())
    
    for _ in range(t):
        head = None
        head2 = None
        nums = list(map(int, input().split()))

        n = len(nums)
        head = addToTheLast(head, Node(nums[0]))
        head2 = addToTheLast(head2, Node(nums[0]))

        for i in range(1, n):
            head = addToTheLast(head, Node(nums[i]))
            head2 = addToTheLast(head2, Node(nums[i]))

        nums2 = list(map(int, input().split()))
        q = len(nums2) // 2

        for i in range(q):
            a = nums2[2 * i]
            b = nums2[2 * i + 1]

            tempA = head
            temp2A = head2
            for _ in range(a - 1):
                tempA = tempA.next
                temp2A = temp2A.next

            tempB = head
            temp2B = head2
            for _ in range(b - 1):
                tempB = tempB.next
                temp2B = temp2B.next

            if a <= n:
                tempA.random = tempB
                temp2A.random = temp2B

        solution = Solution()
        res = solution.copyList(head)

        if validation(head, res) and validation(head2, res):
            print("true")
        else:
            print("false")
