class Solution:
    def decodeString(self, s: str) -> str:
        count_stack = []
        string_stack = []
        current_string = ""
        num = 0
        
        for ch in s:
            if ch.isdigit():
                num = num * 10 + int(ch)  # Handle multi-digit numbers
            elif ch == "[":
                count_stack.append(num)
                string_stack.append(current_string)
                current_string = ""
                num = 0
            elif ch == "]":
                repeat_count = count_stack.pop()
                decoded_string = string_stack.pop()
                current_string = decoded_string + current_string * repeat_count
            else:
                current_string += ch
        
        return current_string

# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.decodeString(s))
