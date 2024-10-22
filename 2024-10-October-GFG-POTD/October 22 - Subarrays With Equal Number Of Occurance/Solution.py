from collections import defaultdict

class Solution:

    def sameOccurrence(self, arr, x, y):
        # Dictionary to store the count of balances
        balance_map = defaultdict(int)
        balance_map[0] = 1  # Initialize with balance 0 occurring once (for empty subarray)

        balance = 0
        result = 0

        # Traverse the array
        for num in arr:
            # Update balance based on x, y, or other numbers
            if num == x:
                balance += 1  # Increment balance for x
            elif num == y:
                balance -= 1  # Decrement balance for y

            # If the same balance occurred before, it means we found subarrays
            # with the same occurrence of x and y
            result += balance_map[balance]

            # Update the balance_map with the current balance
            balance_map[balance] += 1

        return result

# Driver Code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))  # Input array
        x = int(input())
        y = int(input())
        ob = Solution()
        ans = ob.sameOccurrence(arr, x, y)
        print(ans)
