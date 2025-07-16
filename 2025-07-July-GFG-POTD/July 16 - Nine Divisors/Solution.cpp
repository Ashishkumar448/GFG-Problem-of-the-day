#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    static int countNumbers(int n) {
        int limit = sqrt(n) + 1;
        vector<bool> isPrime(limit + 1, true);
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
        vector<int> primes;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        int count = 0;

        // Case 1: Numbers of form p^8
        for (int p : primes) {
            long long val = 1;
            for (int i = 0; i < 8; i++) val *= p;
            if (val <= n) count++;
            else break;
        }

        // Case 2: Numbers of form p^2 * q^2
        int size = primes.size();
        for (int i = 0; i < size; i++) {
            long long p2 = (long long)primes[i] * primes[i];
            for (int j = i + 1; j < size; j++) {
                long long q2 = (long long)primes[j] * primes[j];
                if (p2 * q2 <= n) count++;
                else break;
            }
        }

        return count;
    }
};
