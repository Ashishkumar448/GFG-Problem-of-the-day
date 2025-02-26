//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String line = sc.nextLine();
            String[] input = line.split(" ");
            int[] arr = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            Solution solution = new Solution();
            ArrayList<Integer> result = solution.maxOfMins(arr);
            for (int val : result) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends



class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];

        // Stack to find previous smaller element
        Stack<Integer> stack = new Stack<>();
        
        // Finding previous smaller for each element
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? i + 1 : i - stack.peek();
            stack.push(i);
        }

        // Clear stack for next calculation
        stack.clear();
        
        // Finding next smaller for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? n - i : stack.peek() - i;
            stack.push(i);
        }

        // Store results in an array
        int[] result = new int[n + 1]; // To store max of minimum for each window size
        
        // Fill the result array based on window sizes
        for (int i = 0; i < n; i++) {
            int windowSize = left[i] + right[i] - 1;
            result[windowSize] = Math.max(result[windowSize], arr[i]);
        }

        // Fill remaining values to propagate the max values
        for (int i = n - 1; i >= 1; i--) {
            result[i] = Math.max(result[i], result[i + 1]);
        }

        // Convert result to ArrayList
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            ans.add(result[i]);
        }
        
        return ans;
    }
}
