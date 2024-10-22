//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.HashMap;


// } Driver Code Ends
// User function Template for Java

class Solution {

    static int sameOccurrence(int arr[], int x, int y) {
        // write code here
         // Map to store the count of balances
        HashMap<Integer, Integer> balanceMap = new HashMap<>();
        balanceMap.put(0, 1);  // Initialize with balance 0 occurring once (for empty subarray)
        
        int balance = 0;
        int result = 0;
        
        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            // Update balance based on x, y, or other numbers
            if (arr[i] == x) {
                balance += 1;  // Increment balance for x
            } else if (arr[i] == y) {
                balance -= 1;  // Decrement balance for y
            }
            // If the same balance occurred before, it means we found subarrays
            // with the same occurrence of x and y
            result += balanceMap.getOrDefault(balance, 0);
            
            // Update the balanceMap with the current balance
            balanceMap.put(balance, balanceMap.getOrDefault(balance, 0) + 1);
        }
        
        return result;
    }
}

//{ Driver Code Starts.
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int ans = ob.sameOccurrence(arr, x, y);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends
