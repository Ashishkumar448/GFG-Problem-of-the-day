#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(vector<int>& coins, int sum) {
        if (sum == 0) return 0;

        vector<int> dp(sum + 1, sum + 1);
        dp[0] = 0;

        for (int i = 1; i <= sum; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[sum] == sum + 1) ? -1 : dp[sum];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> coins(k);
        for (int i = 0; i < k; i++) {
            cin >> coins[i];
        }
        int sum;
        cin >> sum;
        Solution obj;
        cout << obj.minCoins(coins, sum) << endl;
    }
    return 0;
}
