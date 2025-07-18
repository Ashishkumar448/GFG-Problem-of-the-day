class Solution {
    public int lcmTriplets(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;

        long result = 0;

        // If n is odd, try n, n-1, n-2
        if (n % 2 != 0) {
            result = lcm(n, lcm(n - 1, n - 2));
        } else {
            // Try multiple combinations for even n
            long l1 = lcm(n, lcm(n - 1, n - 3));
            long l2 = lcm(n, lcm(n - 1, n - 2));
            long l3 = lcm(n - 1, lcm(n - 2, n - 3));
            result = Math.max(l1, Math.max(l2, l3));
        }

        return (int) result;
    }

    private long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
}
