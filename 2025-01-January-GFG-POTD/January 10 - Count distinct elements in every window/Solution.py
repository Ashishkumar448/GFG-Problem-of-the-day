from collections import defaultdict

class Solution:
    def countDistinct(self, arr, n, k):
        result = []
        freq_map = defaultdict(int)

        # Process the first window
        for i in range(k):
            freq_map[arr[i]] += 1
        result.append(len(freq_map))

        # Slide the window
        for i in range(k, n):
            # Remove the element going out of the window
            outgoing = arr[i - k]
            freq_map[outgoing] -= 1
            if freq_map[outgoing] == 0:
                del freq_map[outgoing]

            # Add the element coming into the window
            incoming = arr[i]
            freq_map[incoming] += 1

            # Add the size of the map (distinct count) to the result
            result.append(len(freq_map))

        return result


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())
        n = len(arr)

        solution = Solution()
        ans = solution.countDistinct(arr, n, k)
        print(" ".join(map(str, ans)))
