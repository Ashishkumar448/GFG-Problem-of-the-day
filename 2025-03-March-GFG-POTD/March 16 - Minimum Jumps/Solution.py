class Solution:
    def minJumps(self, arr):
        n = len(arr)
        if n <= 1:
            return 0  # Already at the last index
        if arr[0] == 0:
            return -1  # Can't move forward
        
        maxReach = arr[0]  # The farthest index we can reach
        steps = arr[0]     # Steps we can still take
        jumps = 1          # Initial jump count

        for i in range(1, n):
            if i == n - 1:
                return jumps  # Reached the end
            
            maxReach = max(maxReach, i + arr[i])  # Update maxReach
            steps -= 1  # Use a step
            
            if steps == 0:  # Need to jump
                jumps += 1
                if i >= maxReach:
                    return -1  # Can't reach further
                steps = maxReach - i  # Refill steps
        
        return -1

# Driver code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        print(Solution().minJumps(arr))
