class Solution {
    static final int MAX = 10000;
    
    public int cntCoprime(int[] arr) {
        int[] freq = new int[MAX + 1];

        // Frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // Count how many numbers are divisible by d
        int[] cnt = new int[MAX + 1];
        for (int d = 1; d <= MAX; d++) {
            for (int multiple = d; multiple <= MAX; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // Calculate Mobius function
        int[] mobius = mobiusSieve(MAX);

        long result = 0;

        for (int d = 1; d <= MAX; d++) {
            if (mobius[d] == 0) continue;
            long c = cnt[d];
            result += mobius[d] * c * (c - 1) / 2;
        }

        return (int)result;
    }

    // Mobius function using modified Sieve of Eratosthenes
    private int[] mobiusSieve(int n) {
        int[] mu = new int[n + 1];
        Arrays.fill(mu, 1);
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    isPrime[j] = false;
                }
                long square = 1L * i * i;
                for (long j = square; j <= n; j += square) {
                    mu[(int)j] = 0;
                }
            }
        }

        return mu;
    }
}
