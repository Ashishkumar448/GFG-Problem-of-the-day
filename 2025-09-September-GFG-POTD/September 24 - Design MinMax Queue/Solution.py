from collections import deque

class SpecialQueue:
    def __init__(self):
        self.q = deque()
        self.minDeque = deque()
        self.maxDeque = deque()

    def enqueue(self, x: int) -> None:
        self.q.append(x)

        # Maintain minDeque in increasing order
        while self.minDeque and self.minDeque[-1] > x:
            self.minDeque.pop()
        self.minDeque.append(x)

        # Maintain maxDeque in decreasing order
        while self.maxDeque and self.maxDeque[-1] < x:
            self.maxDeque.pop()
        self.maxDeque.append(x)

    def dequeue(self) -> None:
        if self.q:
            val = self.q.popleft()

            if self.minDeque and self.minDeque[0] == val:
                self.minDeque.popleft()
            if self.maxDeque and self.maxDeque[0] == val:
                self.maxDeque.popleft()

    def getFront(self) -> int:
        return self.q[0]

    def getMin(self) -> int:
        return self.minDeque[0]

    def getMax(self) -> int:
        return self.maxDeque[0]
