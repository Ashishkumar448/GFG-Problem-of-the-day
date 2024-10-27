# { Driver Code Starts
import sys
input = sys.stdin.read

class Solution:
    def findTriplet(self, arr):
        n = len(arr)
        
        # Sort the array to use the two-pointer technique
        arr.sort()
        
        # Iterate through each element to see if it can be the sum of any two others
        for i in range(n):
            target = arr[i]  # Assume arr[i] is the sum of two other elements
            left = 0         # Start pointer
            right = n - 1    # End pointer
            
            # Adjust left and right pointers to avoid using the target element itself
            while left < right:
                if left == i:
                    left += 1  # Skip if left pointer is on the target element
                elif right == i:
                    right -= 1 # Skip if right pointer is on the target element
                else:
                    # Sum of two elements
                    sum = arr[left] + arr[right]
                    
                    if sum == target:
                        return True  # Found a triplet where sum of two elements equals the third
                    elif sum < target:
                        left += 1  # Move left pointer right to increase the sum
                    else:
                        right -= 1  # Move right pointer left to decrease the sum
        
        return False  # No such triplet found

# { Driver Code Starts.
if __name__ == "__main__":
    input_data = input().splitlines()
    t = int(input_data[0])  # Number of test cases
    
    line_idx = 1
    for _ in range(t):
        arr = list(map(int, input_data[line_idx].split()))
        line_idx += 1
        
        obj = Solution()
        res = obj.findTriplet(arr)
        print("true" if res else "false")
        print("~")
# } Driver Code Ends
