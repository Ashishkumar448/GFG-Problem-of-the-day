#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        
        long long count = 0;
        int xr = 0;
        
        // Base case: prefix XOR 0 appears once
        mp[0] = 1;
        
        for (int num : arr) {
            xr ^= num;
            
            // If (xr ^ k) exists, add its frequency
            if (mp.find(xr ^ k) != mp.end()) {
                count += mp[xr ^ k];
            }
            
            // Update frequency of current prefix xor
            mp[xr]++;
        }
        
        return count;
    }
};
