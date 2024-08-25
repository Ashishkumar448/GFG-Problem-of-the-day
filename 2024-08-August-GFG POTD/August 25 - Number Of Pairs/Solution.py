import bisect

class Solution:
    # Function to count number of pairs such that x^y is greater than y^x.
    def countPairs(self, x, y, M, N):
        # Sort y[] so we can use binary search.
        y.sort()

        # Count the frequency of each number in y[].
        freq = [0] * 5
        for num in y:
            if num < 5:
                freq[num] += 1

        totalPairs = 0

        # Traverse all elements in x[].
        for num in x:
            totalPairs += self.countPairsForX(num, y, N, freq)

        return totalPairs

    def countPairsForX(self, x, y, N, freq):
        # If x is 0, no valid pairs.
        if x == 0:
            return 0

        # If x is 1, pairs are valid only with y = 0.
        if x == 1:
            return freq[0]

        # Find the index of the first number in y[] that is greater than x.
        idx = bisect.bisect_right(y, x)

        # All elements with index >= idx satisfy x^y > y^x.
        count = N - idx

        # For x = 2, we need to add the pairs with y = 0, y = 1.
        count += freq[0] + freq[1]

        # For x = 2, subtract pairs where y = 3 and y = 4.
        if x == 2:
            count -= (freq[3] + freq[4])

        # For x = 3, add pairs where y = 2.
        if x == 3:
            count += freq[2]

        return count

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        x = list(map(int, input().split()))
        y = list(map(int, input().split()))
        solution = Solution()
        print(solution.countPairs(x, y, len(x), len(y)))
