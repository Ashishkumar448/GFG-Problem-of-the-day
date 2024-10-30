//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int ans = ob.countPairsWithDiffK(arr, k);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    int countPairsWithDiffK(int[] arr, int k) {
        // HashMap to store frequencies of elements
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        
        // Fill the frequency map
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        int count = 0;
        
        // Iterate over each unique element in the map
        for (int num : freqMap.keySet()) {
            if (k == 0) {
                // Special case: count pairs of the same element if k is 0
                int freq = freqMap.get(num);
                count += (freq * (freq - 1)) / 2;
            } else {
                // Check if num + k is in the map and add valid pairs
                if (freqMap.containsKey(num + k)) {
                    count += freqMap.get(num) * freqMap.get(num + k);
                }
            }
        }
        
        return count;
    }
}
