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
            System.out.println(new Solution().inversionCount(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to count inversions in the array.
    static int inversionCount(int arr[]) {
        // Your Code Here
         // Create a temporary array for merge sort.
        int temp[] = new int[arr.length];
        return mergeSortAndCount(arr, temp, 0, arr.length - 1);
    }

    // Function to implement merge sort and count inversions.
    static int mergeSortAndCount(int arr[], int temp[], int left, int right) {
        int mid, inversionCount = 0;

        if (left < right) {
            // Find the middle point.
            mid = (left + right) / 2;

            // Recursively count inversions in the left and right halves.
            inversionCount += mergeSortAndCount(arr, temp, left, mid);
            inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

            // Merge the two halves and count cross inversions.
            inversionCount += mergeAndCount(arr, temp, left, mid, right);
        }

        return inversionCount;
    }

    // Function to merge two halves and count cross inversions.
    static int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
        int i = left;      // Starting index for the left subarray.
        int j = mid + 1;   // Starting index for the right subarray.
        int k = left;      // Starting index to store sorted elements in temp.
        int inversionCount = 0;

        // Merge the two subarrays into temp[].
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // Inversion found because arr[i] > arr[j].
                temp[k++] = arr[j++];
                inversionCount += (mid + 1 - i); // Count all remaining elements in left subarray.
            }
        }

        // Copy remaining elements of the left subarray (if any).
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of the right subarray (if any).
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted elements back into the original array.
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inversionCount;
    }
}
