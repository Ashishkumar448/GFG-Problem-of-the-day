#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // Sort both arrays
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int moves = 0;
        
        // Sum absolute differences
        for (int i = 0; i < chairs.size(); i++) {
            moves += abs(chairs[i] - passengers[i]);
        }
        
        return moves;
    }
};
