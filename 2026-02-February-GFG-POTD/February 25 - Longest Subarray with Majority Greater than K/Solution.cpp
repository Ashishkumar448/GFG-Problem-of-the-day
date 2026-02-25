#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            // Convert to +1 / -1
            if (arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;
            
            // If prefix sum > 0, whole array till i is valid
            if (prefixSum > 0) {
                maxLen = i + 1;
            } 
            else {
                // Check if prefixSum - 1 exists
                if (mp.find(prefixSum - 1) != mp.end()) {
                    maxLen = max(maxLen, i - mp[prefixSum - 1]);
                }
            }
            
            // Store first occurrence only
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};
