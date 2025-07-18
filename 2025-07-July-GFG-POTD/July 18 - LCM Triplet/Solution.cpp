class Solution {
public:
    int lcmTriplets(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;

        long long result = 0;

        if (n % 2 != 0) {
            result = lcm(n, lcm(n - 1, n - 2));
        } else {
            long long l1 = lcm(n, lcm(n - 1, n - 3));
            long long l2 = lcm(n, lcm(n - 1, n - 2));
            long long l3 = lcm(n - 1, lcm(n - 2, n - 3));
            result = max({l1, l2, l3});
        }

        return (int)result;
    }

private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }
};
