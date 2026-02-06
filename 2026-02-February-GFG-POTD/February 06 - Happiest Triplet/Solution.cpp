#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int bestDiff = INT_MAX;
        int bestSum = INT_MAX;

        vector<int> result(3);

        while (i < a.size() && j < b.size() && k < c.size()) {

            int x = a[i], y = b[j], z = c[k];

            int currMin = min({x, y, z});
            int currMax = max({x, y, z});

            int currDiff = currMax - currMin;
            int currSum = x + y + z;

            if (currDiff < bestDiff || 
               (currDiff == bestDiff && currSum < bestSum)) {

                bestDiff = currDiff;
                bestSum = currSum;

                result = {x, y, z};
            }

            // Move the pointer having the minimum value
            if (currMin == x) i++;
            else if (currMin == y) j++;
            else k++;
        }

        // Sort in decreasing order
        sort(result.begin(), result.end(), greater<int>());
        return result;
    }
};
