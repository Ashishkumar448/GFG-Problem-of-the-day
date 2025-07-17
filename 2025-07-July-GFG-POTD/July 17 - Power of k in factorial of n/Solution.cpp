#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxKPower(int n, int k) {
        unordered_map<int, int> primeFactors;
        int num = k;

        // Prime factorization of k
        for (int i = 2; i * i <= num; ++i) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            primeFactors[k]++;
        }

        int result = INT_MAX;

        for (auto& entry : primeFactors) {
            int p = entry.first;
            int a = entry.second;

            int count = 0;
            int temp = n;
            while (temp > 0) {
                temp /= p;
                count += temp;
            }

            result = min(result, count / a);
        }

        return result;
    }
};
