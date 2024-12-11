class Solution:
    # Function to merge the arrays.
    def mergeArrays(self, a, b):
        n, m = len(a), len(b)
        gap = self.nextGap(n + m)

        while gap > 0:
            i, j = 0, 0

            # Compare and swap within the first array.
            while i + gap < n:
                if a[i] > a[i + gap]:
                    a[i], a[i + gap] = a[i + gap], a[i]
                i += 1

            # Compare and swap between arrays.
            j = gap - n if gap > n else 0
            while i < n and j < m:
                if a[i] > b[j]:
                    a[i], b[j] = b[j], a[i]
                i += 1
                j += 1

            # Compare and swap within the second array.
            while j + gap < m:
                if b[j] > b[j + gap]:
                    b[j], b[j + gap] = b[j + gap], b[j]
                j += 1

            # Calculate the next gap.
            gap = self.nextGap(gap)

    # Function to calculate the next gap.
    def nextGap(self, gap):
        if gap <= 1:
            return 0
        return (gap // 2) + (gap % 2)

# Driver Code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))

        ob = Solution()
        ob.mergeArrays(a, b)

        print(" ".join(map(str, a)))
        print(" ".join(map(str, b)))
