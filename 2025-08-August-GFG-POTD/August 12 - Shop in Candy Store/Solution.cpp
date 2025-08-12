#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        
        // Calculate min cost
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i];
            i++;
            j -= k; // take k most expensive ones for free
        }
        
        // Calculate max cost
        int maxCost = 0;
        i = 0;
        j = n - 1;
        while (i <= j) {
            maxCost += prices[j];
            j--;
            i += k; // take k cheapest ones for free
        }
        
        return {minCost, maxCost};
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 2, 1, 4};
    int k = 2;
    vector<int> result = sol.minMaxCandy(prices, k);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
