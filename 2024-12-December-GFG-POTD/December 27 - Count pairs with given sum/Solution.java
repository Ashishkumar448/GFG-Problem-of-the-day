import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {

    int countPairs(int arr[], int target) {
        // Create a hash map to store frequencies of elements
        Map<Integer, Integer> freqMap = new HashMap<>();
        int count = 0;

        // Traverse the array
        for (int num : arr) {
            int complement = target - num;

            // If the complement is already in the map, increment the count
            if (freqMap.containsKey(complement)) {
                count += freqMap.get(complement);
            }

            // Add the current number to the map
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        return count;
    }
}

// Driver code
class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String line = read.readLine().trim();
            String[] numsStr = line.split(" ");
            int[] nums = new int[numsStr.length];
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int target = Integer.parseInt(read.readLine());

            Solution obj = new Solution();
            System.out.println(obj.countPairs(nums, target));
            System.out.println("~");
        }
    }
}
