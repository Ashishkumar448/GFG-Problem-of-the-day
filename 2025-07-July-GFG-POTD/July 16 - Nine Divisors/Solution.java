class Solution {
    public static int countNumbers(int n) {
        int limit = (int)Math.sqrt(n) + 1;
        boolean[] isPrime = new boolean[limit + 1];
        for (int i = 0; i <= limit; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect primes
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) primes.add(i);
        }

        int count = 0;

        // Case 1: Numbers of form p^8
        for (int p : primes) {
            long val = 1L;
            for (int i = 0; i < 8; i++) val *= p;
            if (val <= n) count++;
            else break;
        }

        // Case 2: Numbers of form p^2 * q^2
        int size = primes.size();
        for (int i = 0; i < size; i++) {
            long p2 = (long)primes.get(i) * primes.get(i);
            for (int j = i + 1; j < size; j++) {
                long q2 = (long)primes.get(j) * primes.get(j);
                if (p2 * q2 <= n) count++;
                else break;
            }
        }

        return count;
    }
}
