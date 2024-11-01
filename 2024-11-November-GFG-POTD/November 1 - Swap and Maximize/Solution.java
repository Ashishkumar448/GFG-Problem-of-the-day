//{ Driver Code Starts
import java.io.*;
import java.util.*;

// Driver class

// } Driver Code Ends
// User function Template for Java

class Solution {
    public long maxSum(Long[] arr) {
        // code here
         // Step 1: Sort the array
        Arrays.sort(arr);
        
        // Create a new array to store elements in high-low order
        Long[] newArr = new Long[arr.length];
        
        // Step 2: Fill newArr with elements in alternating high-low order
        int left = 0, right = arr.length - 1;
        int index = 0;
        
        while (left <= right) {
            if (index % 2 == 0) {
                newArr[index] = arr[left];
                left++;
            } else {
                newArr[index] = arr[right];
                right--;
            }
            index++;
        }
        
        // Step 3: Calculate the sum of absolute differences
        long maxSum = 0;
        for (int i = 0; i < newArr.length - 1; i++) {
            maxSum += Math.abs(newArr[i] - newArr[i + 1]);
        }
        
        // Add the absolute difference between the last and first element to close the loop
        maxSum += Math.abs(newArr[newArr.length - 1] - newArr[0]);
        
        return maxSum;
    }
}


//{ Driver Code Starts.
class Main {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the Long integers
            ArrayList<Long> array = new ArrayList<>();

            // Parse the tokens into Long integers and add to the array
            for (String token : tokens) {
                array.add(Long.parseLong(token));
            }

            // Convert ArrayList to array
            Long[] arr = new Long[array.size()];
            array.toArray(arr);

            Solution ob = new Solution();

            // Call maxSum method and print result
            long ans = ob.maxSum(arr);
            System.out.println(ans);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends
