//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    static int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();
    
    while (testCases--) {
        int W;
        cin >> W;
        cin.ignore();
        
        string valStr, wtStr;
        getline(cin, valStr);
        getline(cin, wtStr);
        
        vector<int> val, wt;
        stringstream vs(valStr), ws(wtStr);
        int num;
        
        while (vs >> num) val.push_back(num);
        while (ws >> num) wt.push_back(num);

        cout << Solution::knapsack(W, val, wt) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
