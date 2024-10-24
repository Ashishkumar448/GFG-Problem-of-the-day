//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            ArrayList<Integer> array1 = new ArrayList<Integer>();
            String line = read.readLine();
            String[] tokens = line.split(" ");
            for (String token : tokens) {
                array1.add(Integer.parseInt(token));
            }
            ArrayList<Integer> v = new ArrayList<Integer>();
            int[] arr = new int[array1.size()];
            int idx = 0;
            for (int i : array1) arr[idx++] = i;

            v = new Solution().modifyAndRearrangeArr(arr);

            for (int i = 0; i < v.size(); i++) System.out.print(v.get(i) + " ");

            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static ArrayList<Integer> modifyAndRearrangeArr(int arr[]) {
        // Complete the function
        // Step 1: Modify the array by merging adjacent duplicate elements
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] == arr[i + 1] && arr[i] != 0) {
                arr[i] = arr[i] * 2;  // Merge duplicates
                arr[i + 1] = 0;  // Set next element to 0
            }
        }

        // Step 2: Rearrange the array by moving all zeroes to the end
        ArrayList<Integer> result = new ArrayList<>();
        int zeroCount = 0;

        // Add non-zero elements to the result list
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                result.add(arr[i]);
            } else {
                zeroCount++;
            }
        }

        // Append the zeroes at the end of the result list
        while (zeroCount-- > 0) {
            result.add(0);
        }

        return result;
    }
}
