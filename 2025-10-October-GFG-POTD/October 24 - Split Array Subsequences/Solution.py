from collections import Counter, defaultdict

class Solution:
    def isPossible(self, arr, k):
        count = Counter(arr)
        endAt = defaultdict(int)

        for num in arr:
            if count[num] == 0:
                continue

            # Case 1: Extend an existing subsequence
            if endAt[num - 1] > 0:
                endAt[num - 1] -= 1
                endAt[num] += 1
                count[num] -= 1
            else:
                # Case 2: Start a new subsequence of length k
                possible = True
                for i in range(k):
                    if count[num + i] <= 0:
                        possible = False
                        break
                if not possible:
                    return False

                for i in range(k):
                    count[num + i] -= 1
                endAt[num + k - 1] += 1

        return True


# Example usage
if __name__ == "__main__":
    s = Solution()
    print(s.isPossible([2,2,3,3,4,5], 2))  # True
    print(s.isPossible([1,1,1,1,1], 4))    # False
    print(s.isPossible([1,2,3,3,4,5], 3))  # True
