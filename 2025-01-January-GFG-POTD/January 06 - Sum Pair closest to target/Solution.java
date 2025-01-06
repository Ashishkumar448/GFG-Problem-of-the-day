//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            ArrayList<Integer> array = new ArrayList<>();

            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int target = Integer.parseInt(br.readLine());

            Solution ob = new Solution();
            List<Integer> res = ob.sumClosest(arr, target);
            if (res.isEmpty()) {
                System.out.print("[]");
            } else {
                for (Integer num : res) {
                    System.out.print(num + " ");
                }
            }
            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        // code here
        // Sort the array to enable two-pointer technique
        Arrays.sort(arr);
        int n = arr.length;
        
        // Edge case: if less than two elements, return empty list
        if (n < 2) return new ArrayList<>();
        
        int closestSum = Integer.MAX_VALUE;
        int maxAbsDifference = Integer.MIN_VALUE;
        List<Integer> result = new ArrayList<>();
        
        int left = 0, right = n - 1;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            // Update closest sum and result pair if closer to target
            if (Math.abs(sum - target) < Math.abs(closestSum - target) || 
               (Math.abs(sum - target) == Math.abs(closestSum - target) 
                && Math.abs(arr[right] - arr[left]) > maxAbsDifference)) {
                
                closestSum = sum;
                maxAbsDifference = Math.abs(arr[right] - arr[left]);
                result = Arrays.asList(arr[left], arr[right]);
            }
            
            // Move pointers based on sum comparison with target
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return result;
    }
}
