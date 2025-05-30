//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;


// } Driver Code Ends


class Solution {
    public int evaluate(String[] arr) {
        Stack<Integer> stack = new Stack<>();
        
        for (String token : arr) {
            if (isOperator(token)) {
                int b = stack.pop(); // Second operand (top of stack)
                int a = stack.pop(); // First operand (next in stack)
                stack.push(applyOperation(a, b, token));
            } else {
                stack.push(Integer.parseInt(token)); // Push operand to stack
            }
        }
        return stack.pop(); // Final result
    }
    
    private boolean isOperator(String token) {
        return token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/");
    }
    
    private int applyOperation(int a, int b, String operator) {
        switch (operator) {
            case "+": return a + b;
            case "-": return a - b;
            case "*": return a * b;
            case "/": return a / b; // Integer division rounds toward zero
            default: throw new IllegalArgumentException("Invalid operator: " + operator);
        }
    }
}


//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int t = Integer.parseInt(line);
        while (t-- > 0) {
            line = reader.readLine();
            String[] arr = line.split(" ");
            Solution solution = new Solution();
            System.out.println(solution.evaluate(arr));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
