#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cntInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Process each query
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];
            
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            
            result.push_back(right - left);
        }
        
        return result;
    }
};
