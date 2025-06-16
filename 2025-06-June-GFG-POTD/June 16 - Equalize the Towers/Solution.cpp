#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int, int>> towers(n);

        for (int i = 0; i < n; i++) {
            towers[i] = {heights[i], cost[i]};
        }

        sort(towers.begin(), towers.end());

        vector<int> sortedHeights(n), sortedCost(n);
        for (int i = 0; i < n; i++) {
            sortedHeights[i] = towers[i].first;
            sortedCost[i] = towers[i].second;
        }

        vector<long long> prefixCost(n), prefixCostHeight(n);
        prefixCost[0] = sortedCost[0];
        prefixCostHeight[0] = (long long)sortedCost[0] * sortedHeights[0];

        for (int i = 1; i < n; i++) {
            prefixCost[i] = prefixCost[i - 1] + sortedCost[i];
            prefixCostHeight[i] = prefixCostHeight[i - 1] + (long long)sortedCost[i] * sortedHeights[i];
        }

        vector<long long> suffixCost(n), suffixCostHeight(n);
        suffixCost[n - 1] = sortedCost[n - 1];
        suffixCostHeight[n - 1] = (long long)sortedCost[n - 1] * sortedHeights[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixCost[i] = suffixCost[i + 1] + sortedCost[i];
            suffixCostHeight[i] = suffixCostHeight[i + 1] + (long long)sortedCost[i] * sortedHeights[i];
        }

        long long minTotalCost = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long costLeft = 0, costRight = 0;
            int targetHeight = sortedHeights[i];

            if (i > 0) {
                costLeft = (long long)targetHeight * prefixCost[i - 1] - prefixCostHeight[i - 1];
            }

            if (i < n - 1) {
                costRight = suffixCostHeight[i + 1] - (long long)targetHeight * suffixCost[i + 1];
            }

            long long totalCost = costLeft + costRight;
            minTotalCost = min(minTotalCost, totalCost);
        }

        return (int)minTotalCost;
    }
};
