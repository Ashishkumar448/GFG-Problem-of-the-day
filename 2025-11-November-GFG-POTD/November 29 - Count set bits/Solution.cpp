class Solution {
public:
    static int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << (x + 1)) <= n) {
            x++;
        }
        return x;
    }

    static int countSetBits(int n) {
        int count = 0;

        while (n > 0) {
            int x = largestPowerOf2(n);

            // full cycles
            count += x * (1 << (x - 1));

            // remaining numbers
            count += n - (1 << x) + 1;

            n -= (1 << x);
        }

        return count;
    }
};
