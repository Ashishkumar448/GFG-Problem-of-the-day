// User function Template for Java

class Solution {
    public static long[] productExceptSelf(int nums[]) {
        int n = nums.length;
        long[] leftProduct = new long[n];
        long[] rightProduct = new long[n];
        long[] result = new long[n];
        
        // Initialize the first element of leftProduct as 1
        leftProduct[0] = 1;
        for (int i = 1; i < n; i++) {
            leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
        }
        
        // Initialize the last element of rightProduct as 1
        rightProduct[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProduct[i] = nums[i + 1] * rightProduct[i + 1];
        }
        
        // Multiply leftProduct and rightProduct to get the result
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }
        
        return result;
    }
}
