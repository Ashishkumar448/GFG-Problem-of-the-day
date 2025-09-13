#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int verticalSegments = 1, horizontalSegments = 1;
        int cost = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                // vertical cut
                cost += x[i] * horizontalSegments;
                verticalSegments++;
                i++;
            } else {
                // horizontal cut
                cost += y[j] * verticalSegments;
                horizontalSegments++;
                j++;
            }
        }

        while (i < x.size()) {
            cost += x[i] * horizontalSegments;
            i++;
        }

        while (j < y.size()) {
            cost += y[j] * verticalSegments;
            j++;
        }

        return cost;
    }
};
