//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int arr[] = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }

            int[] ans = new Solution().constructLowerArray(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int[] constructLowerArray(int[] nums) {
        // code here
         int n = nums.length;
        int[] result = new int[n];

        if (n == 0) {
            return result;
        }

        // Step 1: Normalize the numbers (convert them to ranks)
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);

        Map<Integer, Integer> rankMap = new HashMap<>();
        int rank = 0;
        for (int num : sortedNums) {
            if (!rankMap.containsKey(num)) {
                rankMap.put(num, ++rank);
            }
        }

        // Step 2: Use BIT to count the smaller elements
        int[] bit = new int[rank + 1];

        for (int i = n - 1; i >= 0; i--) {
            int currentRank = rankMap.get(nums[i]);
            result[i] = query(bit, currentRank - 1);
            update(bit, currentRank);
        }

        return result;
    }

    // Function to update the BIT
    private void update(int[] bit, int index) {
        while (index < bit.length) {
            bit[index]++;
            index += index & -index;
        }
    }

    // Function to query the BIT
    private int query(int[] bit, int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
}
