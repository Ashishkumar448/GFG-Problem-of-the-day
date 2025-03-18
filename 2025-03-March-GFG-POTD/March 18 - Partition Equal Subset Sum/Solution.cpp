#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }

        // If total sum is odd, it's impossible to split into equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // DP table filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] > j) { // If element is greater than sum, exclude it
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Include or exclude the current element
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
