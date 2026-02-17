#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<pair<int,int>> events;
        
        for(int i = 0; i < n; i++) {
            events.push_back({arr[i][0], 1});        // start
            events.push_back({arr[i][1] + 1, -1});   // end + 1 (inclusive)
        }
        
        // Sort by:
        // 1. time ascending
        // 2. if same time -> -1 before +1
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        
        int current = 0;
        int maxOverlap = 0;
        
        for(auto &e : events) {
            current += e.second;
            maxOverlap = max(maxOverlap, current);
        }
        
        return maxOverlap;
    }
};
