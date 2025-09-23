from collections import deque

class Solution:
    def reverseQueue(self, q: deque) -> None:
        # base case
        if not q:
            return

        # step 1: remove the front element
        front = q.popleft()

        # step 2: reverse the remaining queue
        self.reverseQueue(q)

        # step 3: add the removed element at the rear
        q.append(front)


# Example usage
if __name__ == "__main__":
    q = deque([5, 10, 15, 20, 25])
    s = Solution()
    s.reverseQueue(q)
    print(list(q))  # [25, 20, 15, 10, 5]
