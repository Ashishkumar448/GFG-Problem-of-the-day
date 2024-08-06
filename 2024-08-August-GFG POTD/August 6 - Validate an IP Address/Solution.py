# User function Template for python3
class Solution:
    def isValid(self, str):
        # Split the string by "."
        parts = str.split('.')
        
        # Check if the IP address has exactly 4 parts
        if len(parts) != 4:
            return False
        
        for part in parts:
            # Check if the part is not empty and is a valid integer
            if not part.isdigit() or int(part) < 0 or int(part) > 255:
                return False
            
            # Check for leading zeros
            if len(part) > 1 and part[0] == '0':
                return False
        
        return True

# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        if ob.isValid(s):
            print("true")
        else:
            print("false")
# Driver Code Ends
