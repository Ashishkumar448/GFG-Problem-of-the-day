#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& arr) {
        vector<int> res;
        int M = arr.size();

        long long discriminant = 1 + 8LL * M;
        int n = (int)((1 + sqrt(discriminant)) / 2);

        // Edge case n = 2
        if (n == 2) {
            int val1 = arr[0] / 2;
            int val2 = arr[0] - val1;
            res.push_back(val1);
            res.push_back(val2);
            return res;
        }

        long long sumABC = (long long)arr[0] + arr[1] - arr[n - 1];
        int x0 = (int)(sumABC / 2);
        res.push_back(x0);

        for (int i = 0; i < n - 1; i++) {
            res.push_back(arr[i] - x0);
        }

        return res;
    }
};
