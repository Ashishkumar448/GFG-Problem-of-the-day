#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int equalSumSpan(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        
        unordered_map<int, int> mp;
        int prefix1 = 0, prefix2 = 0;
        int maxLen = 0;
        
        // diff 0 at index -1
        mp[0] = -1;
        
        for (int i = 0; i < n; i++) {
            prefix1 += a1[i];
            prefix2 += a2[i];
            
            int diff = prefix1 - prefix2;
            
            if (mp.find(diff) != mp.end()) {
                maxLen = max(maxLen, i - mp[diff]);
            } else {
                mp[diff] = i;   // store first occurrence
            }
        }
        
        return maxLen;
    }
};
