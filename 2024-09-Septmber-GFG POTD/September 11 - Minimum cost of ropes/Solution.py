# { Driver Code Starts
import heapq

class Solution:
    # Function to return the minimum cost of connecting the ropes.
    def minCost(self, arr):
        # Create a min-heap to store the rope lengths
        heapq.heapify(arr)
        
        total_cost = 0
        
        # Combine ropes until only one rope remains
        while len(arr) > 1:
            # Remove the two smallest ropes
            first = heapq.heappop(arr)
            second = heapq.heappop(arr)
            
            # Calculate the cost of connecting these two ropes
            cost = first + second
            total_cost += cost
            
            # Add the combined rope back to the heap
            heapq.heappush(arr, cost)
        
        # Return the total cost
        return total_cost

# Driver code
if __name__ == "__main__":
    t = int(input()) # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.minCost(arr))
# } Driver Code Ends