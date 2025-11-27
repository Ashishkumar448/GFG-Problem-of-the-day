class Solution {
    int subsetXORSum(int arr[]) {
        int n = arr.length;
        int OR = 0;
        
        // Compute OR of all elements
        for (int x : arr) {
            OR |= x;
        }
        
        // Multiply by 2^(n-1)
        return OR * (1 << (n - 1));
    }
}
