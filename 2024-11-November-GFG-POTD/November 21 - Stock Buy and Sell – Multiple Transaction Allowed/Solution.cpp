#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        // Traverse the prices array
        for (int i = 1; i < n; i++) {
            // If the current price is greater than the previous price, add the difference to profit
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle newline after reading t

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> prices;
        int price;

        while (ss >> price) {
            prices.push_back(price);
        }

        Solution ob;
        int res = ob.maximumProfit(prices);

        cout << res << endl;
    }

    return 0;
}
