#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int n = mat.size();    // rows
        int m = mat[0].size(); // cols
        int maxSum = INT_MIN;

        for (int top = 0; top < n; ++top) {
            vector<int> temp(m, 0); // Column sums

            for (int bottom = top; bottom < n; ++bottom) {
                for (int col = 0; col < m; ++col) {
                    temp[col] += mat[bottom][col];
                }

                int currentMax = kadane(temp);
                maxSum = max(maxSum, currentMax);
            }
        }

        return maxSum;
    }

private:
    int kadane(const vector<int>& arr) {
        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};
