class Solution {
    public String findLargest(int[] arr) {
        // Step 1: Convert int[] to String[]
        String[] nums = new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            nums[i] = String.valueOf(arr[i]);
        }

        // Step 2: Sort using custom comparator
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));

        // Step 3: Handle leading zeros
        if (nums[0].equals("0")) {
            return "0";
        }

        // Step 4: Build the result
        StringBuilder result = new StringBuilder();
        for (String num : nums) {
            result.append(num);
        }

        return result.toString();
    }
}
