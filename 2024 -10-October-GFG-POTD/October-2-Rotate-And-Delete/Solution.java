//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends

class Solution {
    public static int rotateDelete(ArrayList<Integer> arr) {
        int n = arr.size();
        int step = 1;
        
        while (n > 1) {
            // Rotate: move the last element to the front
            Collections.rotate(arr, 1);
            
            // Delete: delete the element at index (n - step)
            int removeIndex = n - step;
            if (removeIndex < 0) {
                removeIndex = 0; // If the step exceeds the current size, remove the first element
            }
            arr.remove(removeIndex);
            
            // Reduce size of the list after removal
            n = arr.size();
            step++;
        }
        
        // Return the last remaining element
        return arr.get(0);
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> arr = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                arr.add(Integer.parseInt(token));
            }

            Solution obj = new Solution();
            int res = obj.rotateDelete(arr);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends
