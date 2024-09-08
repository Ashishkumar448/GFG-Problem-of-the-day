# Python implementation of the minimum jumps problem

class Solution:
    @staticmethod
    def minJumps(arr):
        # Edge case: If the array length is 1, no jumps are needed.
        if len(arr) == 1:
            return 0
        
        # If the first element is 0, you can't move anywhere.
        if arr[0] == 0:
            return -1
        
        # Initialize variables
        maxReach = arr[0]  # The farthest point that can be reached.
        steps = arr[0]     # Steps that can be taken with the current jump.
        jumps = 1          # Number of jumps made.
        
        # Start traversing the array
        for i in range(1, len(arr)):
            # Check if we have reached the last element.
            if i == len(arr) - 1:
                return jumps
            
            # Update the farthest point that can be reached.
            maxReach = max(maxReach, i + arr[i])
            
            # Use a step to move forward.
            steps -= 1
            
            # If no steps are remaining
            if steps == 0:
                # We must have used a jump.
                jumps += 1
                
                # If the current index is beyond the maximum reach, return -1.
                if i >= maxReach:
                    return -1
                
                # Reinitialize steps with the amount of steps to reach maxReach from position i.
                steps = maxReach - i
        
        # If we haven't returned inside the loop, it's impossible to reach the end.
        return -1


# Driver code to read input and print output
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        print(Solution.minJumps(arr))
