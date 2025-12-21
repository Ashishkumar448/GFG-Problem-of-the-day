#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        // Step 1: Preprocess positions
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        // Step 2: Answer queries
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            if (mp.find(x) == mp.end()) {
                result.push_back(0);
                continue;
            }

            vector<int>& indices = mp[x];

            // lower_bound: first >= l
            int left = lower_bound(indices.begin(), indices.end(), l) - indices.begin();

            // upper_bound: first > r
            int right = upper_bound(indices.begin(), indices.end(), r) - indices.begin();

            result.push_back(right - left);
        }

        return result;
    }
};
