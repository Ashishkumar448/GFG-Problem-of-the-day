import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());  // Number of test cases

        while (t-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            int a[] = new int[inputArray.length];

            for (int i = 0; i < a.length; i++) {
                a[i] = Integer.parseInt(inputArray[i]);
            }

            Solution ob = new Solution();
            ob.sort012(a);

            for (int num : a) {
                System.out.print(num + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}

class Solution {
    // Function to sort an array of 0s, 1s, and 2s
    public void sort012(int[] arr) {
        int low = 0;       // Pointer for 0s
        int mid = 0;       // Pointer for 1s
        int high = arr.length - 1;  // Pointer for 2s

        while (mid <= high) {
            if (arr[mid] == 0) {
                // Swap arr[low] and arr[mid], then move low and mid pointers
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                // If the current element is 1, just move the mid pointer
                mid++;
            } else {
                // Swap arr[mid] and arr[high], then move high pointer
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }
}
