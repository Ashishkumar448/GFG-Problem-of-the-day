#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        // Build the dp array from bottom up
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (wt[i-1] <= w)
                    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
                else
         
