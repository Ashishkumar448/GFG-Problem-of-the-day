#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSum(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        unordered_map<int, int> map;
        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            if (prefixSum == 0) {
                maxLen = i + 1;
            }

            if (map.find(prefixSum) != map.end()) {
                maxLen = max(maxLen, i - map[prefixSum]);
            } else {
                map[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
