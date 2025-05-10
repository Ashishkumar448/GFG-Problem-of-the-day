//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;


// } Driver Code Ends

// User function Template for Java
class Solution {
    static int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        int[] temp = new int[n];

        // Step 1: Convert array elements
        for (int i = 0; i < n; i++) {
            if (arr[i] > k)
                temp[i] = 1;
            else
                temp[i] = -1;
        }

        // Step 2: Find longest subarray with sum > 0
        Map<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += temp[i];

            if (prefixSum > 0) {
                maxLength = i + 1;
            } else {
                if (!map.containsKey(prefixSum)) {
                    map.put(prefixSum, i);
                }

                if (map.containsKey(prefixSum - 1)) {
                    maxLength = Math.max(maxLength, i - map.get(prefixSum - 1));
                }
            }
        }

        return maxLength;
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");
            int n = tokens.length;
            int[] arr = new int[n];

            int i = 0;
            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                arr[i] = Integer.parseInt(token);
                i++;
            }

            int k = Integer.parseInt(br.readLine().trim());
            System.out.println(new Solution().longestSubarray(arr, k));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
