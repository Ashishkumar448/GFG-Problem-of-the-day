class Solution {
    private static final int MAX = 100010;
    private static boolean[] isPrime = new boolean[MAX];

    // Precompute primes using Sieve of Eratosthenes
    static {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < MAX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    Node primeList(Node head) {
        Node curr = head;
        while (curr != null) {
            curr.val = nearestPrime(curr.val);
            curr = curr.next;
        }
        return head;
    }

    // Find nearest prime to given number
    private int nearestPrime(int num) {
        if (isPrime[num]) return num;
        int left = num - 1;
        int right = num + 1;
        while (left >= 2 || right < MAX) {
            if (left >= 2 && isPrime[left]) return left;
            if (right < MAX && isPrime[right]) return right;
            left--;
            right++;
        }
        return 2; // fallback
    }
}