#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MAX = 10000;

public:
    int cntCoprime(vector<int>& arr) {
        vector<int> freq(MAX + 1, 0);

        // Frequency count
        for (int num : arr)
            freq[num]++;

        // Count of numbers divisible by d
        vector<int> cnt(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++) {
            for (int multiple = d; multiple <= MAX; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // Mobius function
        vector<int> mobius = mobiusSieve(MAX);

        long long result = 0;
        for (int d = 1; d <= MAX; d++) {
            if (mobius[d] == 0) continue;
            long long c = cnt[d];
            result += mobius[d] * c * (c - 1) / 2;
        }

        return (int)result;
    }

private:
    vector<int> mobiusSieve(int n) {
        vector<int> mu(n + 1, 1);
        vector<bool> isPrime(n + 1, true);

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    isPrime[j] = false;
                }
                long long square = 1LL * i * i;
                for (long long j = square; j <= n; j += square) {
                    mu[j] = 0;
                }
            }
        }

        return mu;
    }
};
