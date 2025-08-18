class Solution:
    def hIndex(self, citations: list[int]) -> int:
        n = len(citations)
        count = [0] * (n + 1)

        # Count papers with citation[i], cap at n
        for c in citations:
            if c >= n:
                count[n] += 1
            else:
                count[c] += 1

        total = 0
        # Traverse from high to low
        for i in range(n, -1, -1):
            total += count[i]
            if total >= i:
                return i
        return 0
