import sys

def evaluate(arr):
    stack = []
    
    def is_operator(token):
        return token in {'+', '-', '*', '/'}
    
    def apply_operation(a, b, operator):
        if operator == '+': return a + b
        if operator == '-': return a - b
        if operator == '*': return a * b
        if operator == '/': return int(a / b)  # Integer division rounding towards zero
        raise ValueError(f"Invalid operator: {operator}")
    
    for token in arr:
        if is_operator(token):
            b = stack.pop()  # Second operand
            a = stack.pop()  # First operand
            stack.append(apply_operation(a, b, token))
        else:
            stack.append(int(token))  # Push operand to stack
    
    return stack.pop()  # Final result

if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        arr = sys.stdin.readline().strip().split()
        print(evaluate(arr))
        print("~")
