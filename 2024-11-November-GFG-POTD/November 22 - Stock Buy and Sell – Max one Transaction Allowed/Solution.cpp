// User function Template for C++

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Tracks the minimum price encountered
        int maxProfit = 0;       // Tracks the maximum profit found
        
        // Traverse the prices array
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update minimum price
            } else {
                // Calculate profit and update maxProfit if current profit is greater
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit; // Return maximum profit (0 if no profitable transaction)
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; // Number of prices
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        Solution obj;
        int res = obj.maximumProfit(prices);
        cout << res << endl;
    }
    return 0;
}
