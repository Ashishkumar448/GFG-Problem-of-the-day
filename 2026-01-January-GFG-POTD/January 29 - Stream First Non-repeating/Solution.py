from collections import deque

class Solution:
    def firstNonRepeating(self, s):
        freq = [0] * 26
        q = deque()
        result = []

        for ch in s:
            # Update frequency
            freq[ord(ch) - ord('a')] += 1

            # Add current character to queue
            q.append(ch)

            # Remove repeating characters from front
            while q and freq[ord(q[0]) - ord('a')] > 1:
                q.popleft()

            # Append result for current prefix
            if q:
                result.append(q[0])
            else:
                result.append('#')

        return "".join(result)
