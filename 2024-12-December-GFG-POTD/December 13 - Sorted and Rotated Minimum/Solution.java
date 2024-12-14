//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());

        Solution ob = new Solution(); // Instantiate the Solution object once

        while (t-- > 0) {
            String line = scanner.nextLine();
            String[] elements = line.split(" ");
            int[] arr = new int[elements.length]; // Changed to int[]

            for (int i = 0; i < elements.length; i++) {
                arr[i] = Integer.parseInt(elements[i]);
            }

            System.out.println(ob.findMin(arr));
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int findMin(int[] arr) {
        // complete the function here
        int low = 0, high = arr.length - 1;

        // Binary search for the minimum element
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the high element, the min is in the right half
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // Else, the min is in the left half (including mid)
            else {
                high = mid;
            }
        }

        // At the end, low == high, pointing to the minimum element
        return arr[low];
    }
}
