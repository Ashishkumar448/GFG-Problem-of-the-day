//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        while (tc-- > 0) {
            String s[] = br.readLine().split(" ");
            int arr[] = new int[s.length];

            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }
            int k = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            System.out.println(obj.subarrayXor(arr, k));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public long subarrayXor(int arr[], int k) {
        // code here
        // Map to store the frequency of prefixXOR
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefixXOR = 0;
        long count = 0;

        // Traverse through the array
        for (int num : arr) {
            // Update prefixXOR
            prefixXOR ^= num;

            // If prefixXOR itself is equal to k
            if (prefixXOR == k) {
                count++;
            }

            // Check if prefixXOR ^ k exists in map
            int requiredXOR = prefixXOR ^ k;
            if (map.containsKey(requiredXOR)) {
                count += map.get(requiredXOR);
            }

            // Add the current prefixXOR to the map
            map.put(prefixXOR, map.getOrDefault(prefixXOR, 0) + 1);
        }

        return count;
    }
}
