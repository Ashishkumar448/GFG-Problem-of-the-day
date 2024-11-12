import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] arr = new int[n][2];
            for (int i = 0; i < n; i++) {
                String temp[] = br.readLine().trim().split(" ");
                arr[i][0] = Integer.parseInt(temp[0]);
                arr[i][1] = Integer.parseInt(temp[1]);
            }
            Solution obj = new Solution();
            boolean ans = obj.canAttend(arr);
            System.out.println(ans ? "true" : "false");
        }
    }
}

class Solution {
    static boolean canAttend(int[][] arr) {
        // Sort meetings by start time
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        
        // Check for any overlaps
        for (int i = 1; i < arr.length; i++) {
            // If current meeting starts before the previous one ends, return false
            if (arr[i][0] < arr[i - 1][1]) {
                return false;
            }
        }
        
        // No overlaps found, return true
        return true;
    }
}
