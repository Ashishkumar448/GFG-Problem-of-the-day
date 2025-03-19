#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // If k is large enough, treat it as unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        // DP table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        cin >> k;

        Solution obj;
        cout << obj.maxProfit(k, prices) << endl;
        cout << "~" << endl;
    }

    return 0;
}
