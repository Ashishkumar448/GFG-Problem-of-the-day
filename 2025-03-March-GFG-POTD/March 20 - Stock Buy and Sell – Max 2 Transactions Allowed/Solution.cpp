#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);
        
        // Left to right pass to find max profit for first transaction
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }
        
        // Right to left pass to find max profit for second transaction
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }
        
        // Calculate the maximum combined profit
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) cin >> prices[i];
        Solution sol;
        cout << sol.maxProfit(prices) << endl;
    }
    return 0;
}
