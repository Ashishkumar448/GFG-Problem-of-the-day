class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:

    # Return the sum of last k nodes
    def sumOfLastN_Nodes(self, head, n):
        # Step 1: Calculate the length of the linked list
        length = 0
        current = head
        while current is not None:
            length += 1
            current = current.next

        # If n is greater than the length of the list, reset n to length
        if n > length:
            n = length

        # Step 2: Calculate the starting position
        startPos = length - n

        # Step 3: Traverse to the starting node and calculate the sum
        current = head
        sum_val = 0
        index = 0

        # Traverse the linked list again and sum up the last 'n' nodes
        while current is not None:
            if index >= startPos:
                sum_val += current.data
            index += 1
            current = current.next

        return sum_val


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        n = int(input())
        
        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        
        ob = Solution()
        print(ob.sumOfLastN_Nodes(head, n))
