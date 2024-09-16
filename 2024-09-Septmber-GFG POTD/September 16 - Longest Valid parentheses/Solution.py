class Solution:
    def maxLength(self, S: str) -> int:
        # Stack to store the indices of the characters
        stack = []
        # Initialize the stack with -1 to handle edge cases
        stack.append(-1)
        max_len = 0
        
        # Traverse through the string
        for i, c in enumerate(S):
            # If it's an opening parenthesis, push its index onto the stack
            if c == '(':
                stack.append(i)
            # If it's a closing parenthesis
            else:
                # Pop the top index
                stack.pop()
                
                # If the stack is not empty, calculate the length of the valid substring
                if stack:
                    max_len = max(max_len, i - stack[-1])
                # If the stack is empty, push the current index as a new base
                else:
                    stack.append(i)
                    
        return max_len

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()
        ob = Solution()
        print(ob.maxLength(S))
