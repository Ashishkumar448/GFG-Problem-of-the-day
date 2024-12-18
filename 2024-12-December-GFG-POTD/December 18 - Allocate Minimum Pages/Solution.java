//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            String[] nk = br.readLine().trim().split(" ");
            int k = Integer.parseInt(nk[0]);
            Solution sln = new Solution();
            int ans = sln.findPages(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends



//Back-end complete function Template for Java

class Solution {
    public static int findPages(int[] arr, int k) {
        // code here
         if (arr.length < k) return -1; // Not enough books for students

        int low = Integer.MIN_VALUE, high = 0;
        for (int pages : arr) {
            low = Math.max(low, pages); // Maximum book size
            high += pages;             // Sum of all pages
        }

        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isFeasible(arr, k, mid)) {
                result = mid; // Valid allocation found, try for a smaller maximum
                high = mid - 1;
            } else {
                low = mid + 1; // Increase the allowed maximum
            }
        }
        return result;
    }

    private static boolean isFeasible(int[] arr, int k, int maxPages) {
        int studentsRequired = 1, currentPages = 0;

        for (int pages : arr) {
            if (currentPages + pages > maxPages) {
                studentsRequired++; // Allocate to a new student
                currentPages = pages;

                if (studentsRequired > k) return false; // More students needed than available
            } else {
                currentPages += pages;
            }
        }
        return true;

    }
}
