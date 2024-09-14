//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            ArrayList<Integer> arr = new ArrayList<>();

            for (String s : inputArray) {
                arr.add(Integer.parseInt(s));
            }

            new Solution().rearrange(arr);
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    void rearrange(ArrayList<Integer> arr) {
        // code here
        ArrayList<Integer> pos = new ArrayList<>(); // To store positive numbers
        ArrayList<Integer> neg = new ArrayList<>(); // To store negative numbers

        // Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0) {
                pos.add(num);
            } else {
                neg.add(num);
            }
        }

        // Merging them back into arr alternately
        int i = 0, p = 0, n = 0;
        boolean turnPositive = true;

        // Alternate between positive and negative numbers
        while (p < pos.size() && n < neg.size()) {
            if (turnPositive) {
                arr.set(i++, pos.get(p++));
            } else {
                arr.set(i++, neg.get(n++));
            }
            turnPositive = !turnPositive;
        }

        // If there are remaining positive numbers
        while (p < pos.size()) {
            arr.set(i++, pos.get(p++));
        }

        // If there are remaining negative numbers
        while (n < neg.size()) {
            arr.set(i++, neg.get(n++));
        }
    }
}
