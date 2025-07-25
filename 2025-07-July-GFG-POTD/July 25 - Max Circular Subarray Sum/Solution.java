class Solution {
    public int maxCircularSum(int arr[]) {
        int n = arr.length;
        
        // Step 1: Normal Kadane's algorithm for non-wrapping case
        int max_kadane = kadane(arr);
        
        // Step 2: Calculate total sum of the array
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i]; // Invert the elements
        }
        
        // Step 3: Kadane on inverted array to find min subarray sum
        int max_inverse_kadane = kadane(arr);
        
        // Wrapping case result
        int max_wrap = total_sum + max_inverse_kadane;
        
        // Edge case: If all elements are negative, max_wrap will be 0
        if (max_wrap == 0) return max_kadane;
        
        return Math.max(max_kadane, max_wrap);
    }
    
    // Kadane's algorithm to find max subarray sum
    private int kadane(int[] arr) {
        int max_so_far = arr[0];
        int current_max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            current_max = Math.max(arr[i], current_max + arr[i]);
            max_so_far = Math.max(max_so_far, current_max);
        }
        return max_so_far;
    }

}
