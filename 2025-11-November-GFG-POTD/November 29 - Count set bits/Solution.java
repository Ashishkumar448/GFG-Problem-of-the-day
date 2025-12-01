class Solution {
    public static int countSetBits(int n) {
        int count = 0;
        
        while (n > 0) {
            // Largest power of 2 less than or equal to n
            int x = largestPowerOf2(n);
            
            // Count bits from MSB position
            count += x * (1 << (x - 1));        // full cycles
            count += n - (1 << x) + 1;          // remaining numbers
            
            // Reduce n for next round
            n = n - (1 << x);
        }
        
        return count;
    }
    
    // Returns floor(log2(n))
    private static int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << (x + 1)) <= n) {
            x++;
        }
        return x;
    }
}
