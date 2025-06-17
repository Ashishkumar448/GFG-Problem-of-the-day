#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Prefix sum
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        int minCoins = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int minVal = arr[i];
            int maxAllowed = minVal + k;

            // upper_bound returns iterator to first element > maxAllowed
            int j = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin() - 1;

            long long leftRemove = prefixSum[i];

            long long totalRightCoins = prefixSum[n] - prefixSum[j + 1];
            int countRight = n - j - 1;
            long long maxAllowedTotal = 1LL * countRight * maxAllowed;
            long long rightRemove = totalRightCoins - maxAllowedTotal;

            long long totalRemove = leftRemove + rightRemove;
            minCoins = min(minCoins, (int)totalRemove);
        }

        return minCoins;
    }
};
