class Solution {
    public int maxKPower(int n, int k) {
        // Factorize k into its prime factors
        Map<Integer, Integer> primeFactors = new HashMap<>();
        int num = k;
        for (int i = 2; i * i <= num; i++) {
            while (k % i == 0) {
                primeFactors.put(i, primeFactors.getOrDefault(i, 0) + 1);
                k /= i;
            }
        }
        if (k > 1) {
            primeFactors.put(k, primeFactors.getOrDefault(k, 0) + 1);
        }

        // For each prime factor, use Legendre's formula
        int result = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : primeFactors.entrySet()) {
            int p = entry.getKey();
            int a = entry.getValue();
            int count = 0;
            int temp = n;
            while (temp > 0) {
                temp /= p;
                count += temp;
            }
            result = Math.min(result, count / a);
        }

        return result;
    }

}
