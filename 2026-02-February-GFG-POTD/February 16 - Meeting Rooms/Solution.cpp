#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool canAttend(vector<vector<int>>& arr) {
        // Sort meetings based on start time
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Check for overlap
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < arr[i - 1][1]) {
                return false; // Overlapping meetings
            }
        }

        return true; // No overlaps
    }
};
