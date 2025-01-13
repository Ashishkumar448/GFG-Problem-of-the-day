//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().maxWater(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public int maxWater(int arr[]) {
        // Code Here
        int left = 0; // Left pointer
        int right = arr.length - 1; // Right pointer
        int maxWater = 0; // To store the maximum water

        while (left < right) {
            // Calculate the water between the current pair of lines
            int height = Math.min(arr[left], arr[right]);
            int width = right - left;
            int currentWater = height * width;

            // Update the maximum water if the current one is greater
            maxWater = Math.max(maxWater, currentWater);

            // Move the pointer pointing to the shorter line inward
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
}
