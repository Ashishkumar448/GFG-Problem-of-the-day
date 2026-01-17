class Solution:
    def checkRedundancy(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch == ')':
                has_operator = False

                # Check contents inside parentheses
                while stack and stack[-1] != '(':
                    top = stack.pop()
                    if top in '+-*/':
                        has_operator = True

                # Remove opening '('
                if stack:
                    stack.pop()

                # No operator found → redundant brackets
                if not has_operator:
                    return True
            else:
                stack.append(ch)

        return False
