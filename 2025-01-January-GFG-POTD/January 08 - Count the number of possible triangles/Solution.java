//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }
            System.out.println(new Solution().countTriangles(arr));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to count the number of possible triangles.
    static int countTriangles(int arr[]) {
        // code here
        // Sort the array to simplify the triangle condition check
        Arrays.sort(arr);

        int n = arr.length;
        int count = 0;

        // Fix the largest side one by one
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            // Use two pointers to find valid pairs
            while (left < right) {
                // Check if the sum of arr[left] and arr[right] is greater than arr[i]
                if (arr[left] + arr[right] > arr[i]) {
                    // All elements between left and right form a valid triangle
                    count += (right - left);
                    right--;
                } else {
                    // Move the left pointer forward
                    left++;
                }
            }
        }
        return count;
    }
}
