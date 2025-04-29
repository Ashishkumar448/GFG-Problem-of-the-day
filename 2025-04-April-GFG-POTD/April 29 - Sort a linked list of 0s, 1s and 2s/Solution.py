class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def segregate(self, head):
        if head is None or head.next is None:
            return head

        count = [0, 0, 0]  # count[0] for 0s, count[1] for 1s, count[2] for 2s
        temp = head

        while temp:
            count[temp.data] += 1
            temp = temp.next

        temp = head
        i = 0

        while temp:
            if count[i] == 0:
                i += 1
            else:
                temp.data = i
                count[i] -= 1
                temp = temp.next

        return head

def printList(node):
    while node:
        print(node.data, end=' ')
        node = node.next
    print()

def main():
    t = int(input())

    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        head = None
        tail = None

        if arr:
            head = Node(arr[0])
            tail = head
            for num in arr[1:]:
                tail.next = Node(num)
                tail = tail.next

        ob = Solution()
        head = ob.segregate(head)
        printList(head)
        print("~")

if __name__ == "__main__":
    main()
