class Solution {
     public String findLargest(int[] arr) {
        // Convert integers to String array
        String[] nums = new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            nums[i] = String.valueOf(arr[i]);
        }
        
        // Sort using custom comparator
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        // Edge case: if the largest number is "0"
        if (nums[0].equals("0")) {
            return "0";
        }
        
        // Build final result
        StringBuilder result = new StringBuilder();
        for (String num : nums) {
            result.append(num);
        }
        
        return result.toString();
    }
}
