#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<vector<int>> chainList(n);
        
        for (int i = 0; i < n; i++) {
            chainList[i] = {arr[i]};
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        chainList[i] = chainList[j];
                        chainList[i].push_back(arr[i]);
                    } else if (dp[j] + 1 == dp[i]) {
                        bool update = false;
                        for (int k = 0; k < chainList[j].size(); k++) {
                            if (chainList[j][k] > chainList[i][k]) {
                                update = true;
                                break;
                            } else if (chainList[j][k] < chainList[i][k]) {
                                break;
                            }
                        }
                        if (update) {
                            chainList[i] = chainList[j];
                            chainList[i].push_back(arr[i]);
                        }
                    }
                }
            }
        }
        
        int maxLen = 0;
        vector<int> bestChain;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                bestChain = chainList[i];
            } else if (dp[i] == maxLen) {
                for (int k = 0; k < dp[i]; k++) {
                    if (chainList[i][k] > bestChain[k]) {
                        bestChain = chainList[i];
                        break;
                    } else if (chainList[i][k] < bestChain[k]) {
                        break;
                    }
                }
            }
        }
        
        return bestChain;
    }
};
