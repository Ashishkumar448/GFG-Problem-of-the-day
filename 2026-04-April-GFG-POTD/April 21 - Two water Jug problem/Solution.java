class Solution {
    
    public int minSteps(int m, int n, int d) {
        // If d is more than both jugs
        if (d > Math.max(m, n)) return -1;
        
        // Check if solution exists
        if (d % gcd(m, n) != 0) return -1;
        
        // Try both ways and return minimum
        return Math.min(pour(m, n, d), pour(n, m, d));
    }
    
    // Function to simulate pouring from 'from' jug to 'to' jug
    private int pour(int fromCap, int toCap, int d) {
        int from = fromCap;  // fill source
        int to = 0;          // destination empty
        int step = 1;
        
        while (from != d && to != d) {
            // pour water
            int transfer = Math.min(from, toCap - to);
            to += transfer;
            from -= transfer;
            step++;
            
            // check if done
            if (from == d || to == d) break;
            
            // if source empty → refill
            if (from == 0) {
                from = fromCap;
                step++;
            }
            
            // if destination full → empty it
            if (to == toCap) {
                to = 0;
                step++;
            }
        }
        
        return step;
    }
    
    // GCD function
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
