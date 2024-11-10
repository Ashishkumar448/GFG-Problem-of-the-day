class Solution:
    # Function to return a list containing the union of the two arrays.
    def findUnion(self, a, b):
        result = []
        i, j = 0, 0

        # Traverse both arrays
        while i < len(a) and j < len(b):
            # Avoid duplicates in result
            if result and result[-1] == a[i]:
                i += 1
                continue
            if result and result[-1] == b[j]:
                j += 1
                continue

            if a[i] < b[j]:
                result.append(a[i])
                i += 1
            elif a[i] > b[j]:
                result.append(b[j])
                j += 1
            else:
                result.append(a[i])
                i += 1
                j += 1

        # Add remaining elements of a
        while i < len(a):
            if not result or result[-1] != a[i]:
                result.append(a[i])
            i += 1

        # Add remaining elements of b
        while j < len(b):
            if not result or result[-1] != b[j]:
                result.append(b[j])
            j += 1

        return result

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        # First array input
        a = list(map(int, input().split()))

        # Second array input
        b = list(map(int, input().split()))

        obj = Solution()
        res = obj.findUnion(a, b)
        print(" ".join(map(str, res)))
