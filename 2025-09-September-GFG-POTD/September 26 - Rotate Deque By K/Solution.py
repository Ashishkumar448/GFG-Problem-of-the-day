from collections import deque

class Solution:
    @staticmethod
    def rotateDeque(dq, type, k):
        n = len(dq)
        if n == 0:
            return
        k %= n

        if type == 1:  # Right rotation
            for _ in range(k):
                val = dq.pop()
                dq.appendleft(val)
        elif type == 2:  # Left rotation
            for _ in range(k):
                val = dq.popleft()
                dq.append(val)


# quick test
dq1 = deque([1, 2, 3, 4, 5, 6])
Solution.rotateDeque(dq1, 1, 2)
print(list(dq1))  # [5, 6, 1, 2, 3, 4]

dq2 = deque([10, 20, 30, 40, 50])
Solution.rotateDeque(dq2, 2, 3)
print(list(dq2))  # [40, 50, 10, 20, 30]
