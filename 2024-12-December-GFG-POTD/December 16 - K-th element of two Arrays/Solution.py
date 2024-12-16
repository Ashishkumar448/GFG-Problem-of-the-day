class Solution:
    def kthElement(self, a, b, k):
        # Ensure `a` is the smaller array
        if len(a) > len(b):
            return self.kthElement(b, a, k)

        n, m = len(a), len(b)

        # Define the binary search range
        low = max(0, k - m)
        high = min(k, n)

        while low <= high:
            cut1 = (low + high) // 2
            cut2 = k - cut1

            # Handle out-of-bound elements
            leftA = float('-inf') if cut1 == 0 else a[cut1 - 1]
            leftB = float('-inf') if cut2 == 0 else b[cut2 - 1]
            rightA = float('inf') if cut1 == n else a[cut1]
            rightB = float('inf') if cut2 == m else b[cut2]

            # Check if we found the correct partition
            if leftA <= rightB and leftB <= rightA:
                return max(leftA, leftB)
            elif leftA > rightB:
                # Move towards the left in `a`
                high = cut1 - 1
            else:
                # Move towards the right in `a`
                low = cut1 + 1

        # If the function reaches here, the input is invalid
        return -1


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        
        ob = Solution()
        print(ob.kthElement(a, b, k))
        print("~")
