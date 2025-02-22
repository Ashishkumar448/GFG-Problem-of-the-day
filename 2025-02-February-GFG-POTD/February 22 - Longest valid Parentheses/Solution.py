# Python Implementation
def maxLength(s):
    stack = [-1]  # Base index for valid substring
    max_len = 0

    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                max_len = max(max_len, i - stack[-1])
    
    return max_len

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()
        print(maxLength(S))
        print("~")
