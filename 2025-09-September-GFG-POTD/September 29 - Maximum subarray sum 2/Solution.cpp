#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();

        // prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        deque<int> dq;
        long long ans = LLONG_MIN;

        for (int r = a; r <= n; r++) {
            int l = r - a;

            // maintain increasing order of prefix values
            while (!dq.empty() && prefix[dq.back()] >= prefix[l]) {
                dq.pop_back();
            }
            dq.push_back(l);

            // remove indices outside the [r-b, r-a] window
            while (!dq.empty() && dq.front() < r - b) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                ans = max(ans, prefix[r] - prefix[dq.front()]);
            }
        }

        return (int)ans;
    }
};
