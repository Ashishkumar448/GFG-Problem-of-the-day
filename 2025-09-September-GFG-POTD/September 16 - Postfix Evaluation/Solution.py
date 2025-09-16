import math

class Solution:
    def evaluatePostfix(self, arr):
        stack = []
        
        for token in arr:
            if token in {"+", "-", "*", "/", "^"}:
                b = stack.pop()  # right operand
                a = stack.pop()  # left operand
                result = 0
                
                if token == "+":
                    result = a + b
                elif token == "-":
                    result = a - b
                elif token == "*":
                    result = a * b
                elif token == "/":
                    # floor division handling
                    result = math.floor(a / b)
                elif token == "^":
                    result = int(math.pow(a, b))
                
                stack.append(result)
            else:
                stack.append(int(token))
        
        return stack.pop()
