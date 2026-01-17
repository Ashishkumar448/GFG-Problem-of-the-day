class Solution {
    public static boolean checkRedundancy(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == ')') {
                boolean hasOperator = false;

                // Check contents inside parentheses
                while (!stack.isEmpty() && stack.peek() != '(') {
                    char top = stack.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // Remove opening '('
                stack.pop();

                // No operator found → redundant brackets
                if (!hasOperator) {
                    return true;
                }
            } else {
                stack.push(ch);
            }
        }

        return false;
    }
}
