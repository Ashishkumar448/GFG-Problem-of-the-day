# { Driver Code Starts
class Solution:
    
    # Function to check if brackets are balanced or not.
    def ispar(self, x):
        # Stack to store opening brackets
        stack = []
        
        # Traverse each character in the string
        for ch in x:
            # If the character is an opening bracket, push it to the stack
            if ch in ['(', '{', '[']:
                stack.append(ch)
            # If the character is a closing bracket
            elif ch in [')', '}', ']']:
                # If stack is empty, return False (no matching opening bracket)
                if not stack:
                    return False
                
                # Pop the top element and check if it matches the current closing bracket
                top = stack.pop()
                if (ch == ')' and top != '(') or \
                   (ch == '}' and top != '{') or \
                   (ch == ']' and top != '['):
                    return False
        
        # If the stack is empty, it means all opening brackets were matched
        return not stack

# { Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        st = input().strip()
        
        obj = Solution()
        if obj.ispar(st):
            print("balanced")
        else:
            print("not balanced")
# } Driver Code Ends
