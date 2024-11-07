//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        while (testCases-- > 0) {
            String[] str = br.readLine().trim().split(" ");
            int[] arr = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }

            Solution ob = new Solution();
            List<Integer> result = ob.findSplit(arr);

            if (result.get(0) == -1 && result.get(1) == -1) {
                System.out.println("false");
            } else {
                System.out.println("true");
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    // Function to determine if array arr can be split into three equal sum sets.
    public List<Integer> findSplit(int[] arr) {
        // code here
         List<Integer> result = new ArrayList<>(Arrays.asList(-1, -1));
        
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // If totalSum is not divisible by 3, we cannot split the array.
        if (totalSum % 3 != 0) {
            return result;
        }
        
        int targetSum = totalSum / 3;
        int runningSum = 0, count = 0;
        
        // Traverse the array to find the split points.
        for (int i = 0; i < arr.length; i++) {
            runningSum += arr[i];
            
            if (runningSum == targetSum) {
                runningSum = 0; // Reset runningSum for next part
                count++;
                
                // Set the split points when we find the first two equal parts
                if (count == 1) {
                    result.set(0, i);
                } else if (count == 2) {
                    result.set(1, i + 1);
                    return result;
                }
            }
        }
        
        // If unable to find two split points, return [-1, -1]
        return Arrays.asList(-1, -1);
    }
}
