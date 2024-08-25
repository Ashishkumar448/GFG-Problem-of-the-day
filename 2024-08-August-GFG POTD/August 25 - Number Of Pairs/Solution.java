//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int x[] = new int[str.length];
            for (int i = 0; i < str.length; i++) x[i] = Integer.parseInt(str[i]);
            str = (br.readLine()).trim().split(" ");
            int[] y = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                y[i] = Integer.parseInt(str[i]);
            }
            System.out.println(new Solution().countPairs(x, y, x.length, y.length));
        }
    }
}

// } Driver Code Ends


//Back-end complete function Template for Java
class Solution {
    // Function to count number of pairs such that x^y is greater than y^x.
    public long countPairs(int x[], int y[], int M, int N) {
        // code here
        // Sort y[] so we can use binary search.
        Arrays.sort(y);

        // Count the frequency of each number in y[].
        int[] freq = new int[5];
        for (int i = 0; i < N; i++) {
            if (y[i] < 5) {
                freq[y[i]]++;
            }
        }

        long totalPairs = 0;

        // Traverse all elements in x[].
        for (int i = 0; i < M; i++) {
            totalPairs += countPairsForX(x[i], y, N, freq);
        }

        return totalPairs;
    }

    private long countPairsForX(int x, int[] y, int N, int[] freq) {
        // If x is 0, no valid pairs.
        if (x == 0) return 0;

        // If x is 1, pairs are valid only with y = 0.
        if (x == 1) return freq[0];

        // Find the index of the first number in y[] that is greater than x.
        int idx = Arrays.binarySearch(y, x);
        if (idx < 0) {
            idx = -(idx + 1);
        } else {
            while (idx < N && y[idx] == x) {
                idx++;
            }
        }

        // All elements with index >= idx satisfy x^y > y^x.
        long count = N - idx;

        // For x = 2, we need to add the pairs with y = 0, y = 1.
        count += freq[0] + freq[1];

        // For x = 2, subtract pairs where y = 3 and y = 4.
        if (x == 2) count -= (freq[3] + freq[4]);

        // For x = 3, add pairs where y = 2.
        if (x == 3) count += freq[2];

        return count;
    }
}
