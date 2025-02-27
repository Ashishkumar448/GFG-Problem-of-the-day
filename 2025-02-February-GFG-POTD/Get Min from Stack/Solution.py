class Solution:
    def __init__(self):
        self.stack = []
        self.minStack = []

    # Add an element to the top of Stack
    def push(self, x: int):
        self.stack.append(x)
        if not self.minStack or x <= self.minStack[-1]:
            self.minStack.append(x)

    # Remove the top element from the Stack
    def pop(self):
        if self.stack:
            if self.stack[-1] == self.minStack[-1]:
                self.minStack.pop()
            self.stack.pop()

    # Returns top element of the Stack
    def peek(self) -> int:
        return self.stack[-1] if self.stack else -1

    # Finds minimum element of Stack
    def getMin(self) -> int:
        return self.minStack[-1] if self.minStack else -1


# Driver Code
if __name__ == "__main__":
    T = int(input())  # Number of test cases

    for _ in range(T):
        q = int(input())  # Number of queries
        g = Solution()

        for _ in range(q):
            query = list(map(int, input().split()))
            qt = query[0]

            if qt == 1:
                g.push(query[1])
            elif qt == 2:
                g.pop()
            elif qt == 3:
                print(g.peek(), end=" ")
            elif qt == 4:
                print(g.getMin(), end=" ")

        print("\n~")
