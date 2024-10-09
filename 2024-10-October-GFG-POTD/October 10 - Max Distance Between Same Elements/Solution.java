//{ Driver Code Starts
import java.util.*;
import java.util.Scanner;


// } Driver Code Ends
class Solution {
    public int maxDistance(int[] arr) {
        // Code here
         // Create a map to store the first occurrence of each element
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxDist = 0; // To store the maximum distance

        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])) {
                // Calculate the distance from the first occurrence
                int dist = i - map.get(arr[i]);
                maxDist = Math.max(maxDist, dist); // Update the maximum distance
            } else {
                // Store the index of the first occurrence
                map.put(arr[i], i);
            }
        }
        return maxDist; // Return the maximum distance found
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String input = sc.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maxDistance(arr));
        }
        sc.close();
    }
}
// } Driver Code Ends
