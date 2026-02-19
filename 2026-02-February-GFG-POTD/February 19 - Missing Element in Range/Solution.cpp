#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        vector<int> result;
        unordered_set<int> s;
        
        // Store array elements in unordered_set
        for (int num : arr) {
            s.insert(num);
        }
        
        // Check for missing numbers in range
        for (int i = low; i <= high; i++) {
            if (s.find(i) == s.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
