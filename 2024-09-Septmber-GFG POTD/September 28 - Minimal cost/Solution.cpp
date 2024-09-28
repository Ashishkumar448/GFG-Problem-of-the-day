// { Driver Code Starts
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to minimize the cost to reach the last index
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0; // Starting point has 0 cost

        // Iterate through each index from 1 to n-1
        for (int i = 1; i < n; i++) {
            // Check up to k steps back
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }

        return dp[n - 1]; // Return the cost to reach the last index
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string line;
        cin.ignore();
        getline(cin, line);
        vector<int> arr;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        cout << sol.minimizeCost(k, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
