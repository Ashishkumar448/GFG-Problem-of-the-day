class Solution {
   public int evaluatePostfix(String[] arr) {
        Stack<Integer> stack = new Stack<>();
        
        for (String token : arr) {
            if (isOperator(token)) {
                int b = stack.pop();  // right operand
                int a = stack.pop();  // left operand
                int result = 0;
                
                switch (token) {
                    case "+": result = a + b; break;
                    case "-": result = a - b; break;
                    case "*": result = a * b; break;
                    case "/": 
                        // floor division handling
                        result = (int) Math.floor((double) a / b);
                        break;
                    case "^": result = (int) Math.pow(a, b); break;
                }
                stack.push(result);
            } else {
                // number
                stack.push(Integer.parseInt(token));
            }
        }
        
        return stack.pop();
    }
    
    private boolean isOperator(String s) {
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("^");
    }
}
