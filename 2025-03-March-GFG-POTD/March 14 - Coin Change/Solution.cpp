// C++ Implementation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, 0);
        
        // Base case: There is one way to make sum 0, by choosing no coins
        dp[0] = 1;
        
        // Process each coin one by one
        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[sum];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        int sum;
        cin >> sum;
        Solution ob;
        cout << ob.count(coins, sum) << endl;
        cout << "~" << endl;
    }
    return 0;
}
