class Solution {
    public ArrayList<Integer> constructArr(int[] arr) {
        ArrayList<Integer> res = new ArrayList<>();
        int M = arr.length;
        
        // 1. Calculate the size of the original array 'n'
        // Formula: n * (n - 1) / 2 = M
        // This is a quadratic equation: n^2 - n - 2M = 0
        // Solving for n: n = (1 + sqrt(1 + 8M)) / 2
        long discriminant = 1 + 8L * M;
        int n = (int)((1 + Math.sqrt(discriminant)) / 2);
        
        // 2. Handle Edge Case: n = 2 (Array size 1)
        if (n == 2) {
            // We only have res[0] + res[1] = arr[0].
            // We can pick an arbitrary valid pair, e.g., splitting roughly in half.
            int val1 = arr[0] / 2;
            int val2 = arr[0] - val1;
            res.add(val1);
            res.add(val2);
            return res;
        }
        
        // 3. Solve for res[0] using the relation derived for n >= 3
        // arr[0]   = res[0] + res[1]
        // arr[1]   = res[0] + res[2]
        // arr[n-1] = res[1] + res[2]
        // Note: Use long to prevent integer overflow during addition
        long sumABC = (long)arr[0] + arr[1] - arr[n-1];
        int x0 = (int)(sumABC / 2);
        res.add(x0);
        
        // 4. Determine the rest of the elements
        // The first n-1 elements of 'arr' are:
        // res[0]+res[1], res[0]+res[2], ..., res[0]+res[n-1]
        for (int i = 0; i < n - 1; i++) {
            // arr[i] corresponds to res[0] + res[i+1]
            // So, res[i+1] = arr[i] - res[0]
            res.add(arr[i] - x0);
        }
        
        return res;
    }
}
