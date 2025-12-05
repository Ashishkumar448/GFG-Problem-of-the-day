class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();

        if (k == 1) return (n == 1) ? costs[0][0] : -1;

        int min1 = 0, min2 = 0, idx1 = -1;

        for (int i = 0; i < n; i++) {
            int newMin1 = INT_MAX, newMin2 = INT_MAX, newIdx1 = -1;

            for (int j = 0; j < k; j++) {
                int currCost = costs[i][j];

                // Add previous best but avoid same color
                if (j == idx1) currCost += min2;
                else currCost += min1;

                if (currCost < newMin1) {
                    newMin2 = newMin1;
                    newMin1 = currCost;
                    newIdx1 = j;
                } else if (currCost < newMin2) {
                    newMin2 = currCost;
                }
            }
            min1 = newMin1;
            min2 = newMin2;
            idx1 = newIdx1;
        }
        return min1;
    }
};
