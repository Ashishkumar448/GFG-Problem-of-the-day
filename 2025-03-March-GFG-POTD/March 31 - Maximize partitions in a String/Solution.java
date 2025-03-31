//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            int ans = obj.maxPartitions(s);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int maxPartitions(String s) {
        // Step 1: Store last occurrence of each character
        Map<Character, Integer> lastOccurrence = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence.put(s.charAt(i), i);
        }

        int partitions = 0;
        int maxLast = 0;
        for (int i = 0; i < s.length(); i++) {
            maxLast = Math.max(maxLast, lastOccurrence.get(s.charAt(i)));

            // Step 2: If current index reaches max last occurrence, create a partition
            if (i == maxLast) {
                partitions++;
            }
        }

        return partitions;
    }
}
