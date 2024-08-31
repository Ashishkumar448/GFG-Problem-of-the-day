//{ Driver Code Starts
import java.util.*;

public class GFG {
    // Function to check if v2 is a subsequence of v1
    public static boolean isSubSequence(int[] v1, int[] v2) {
        int m = v2.length;
        int n = v1.length;
        int j = 0; // For index of v2

        // Traverse v1 and v2
        for (int i = 0; i < n && j < m; i++) {
            if (v1[i] == v2[j]) {
                j++;
            }
        }
        return j == m;
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String[] input = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            int n = arr.length;
            Solution obj = new Solution();
            List<Integer> res = obj.find3Numbers(arr);
            if (!res.isEmpty() && res.size() != 3) {
                System.out.println(-1);
            } else {
                int[] resArray = res.stream().mapToInt(Integer::intValue).toArray();
                if (resArray.length == 0) {
                    System.out.println(0);
                } else if (resArray[0] < resArray[1] && resArray[1] < resArray[2] &&
                           isSubSequence(arr, resArray)) {
                    System.out.println(1);
                } else {
                    System.out.println(-1);
                }
            }
        }
        sc.close();
    }
}

// } Driver Code Ends


/*Complete the function below*/

class Solution {
    // Function to find three numbers such that arr[smaller[i]] < arr[i] <
    // arr[greater[i]]
    public List<Integer> find3Numbers(int[] arr) {
        // code here
        int n = arr.length;
        List<Integer> result = new ArrayList<>();

        if (n < 3) {
            return result; // If less than 3 elements, no subsequence of size 3 exists.
        }

        // Arrays to store the index of the smallest element to the left and the largest element to the right
        int[] leftMin = new int[n];
        int[] rightMax = new int[n];

        leftMin[0] = -1;  // No element to the left of the first element
        int minIndex = 0;

        // Fill the leftMin array
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIndex]) {
                minIndex = i;
                leftMin[i] = -1;  // No smaller element on the left
            } else {
                leftMin[i] = minIndex;  // Index of the smallest element on the left
            }
        }

        rightMax[n - 1] = -1;  // No element to the right of the last element
        int maxIndex = n - 1;

        // Fill the rightMax array
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIndex]) {
                maxIndex = i;
                rightMax[i] = -1;  // No larger element on the right
            } else {
                rightMax[i] = maxIndex;  // Index of the largest element on the right
            }
        }

        // Find the subsequence of size 3
        for (int i = 1; i < n - 1; i++) {
            if (leftMin[i] != -1 && rightMax[i] != -1) {
                result.add(arr[leftMin[i]]);
                result.add(arr[i]);
                result.add(arr[rightMax[i]]);
                return result;  // Return the first found subsequence
            }
        }

        return result;  // No subsequence found
    }
}
