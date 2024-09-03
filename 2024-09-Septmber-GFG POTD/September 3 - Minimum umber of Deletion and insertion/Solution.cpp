// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int lcsLength = longestCommonSubsequence(str1, str2, m, n);

        // Calculate the number of deletions and insertions
        int deletions = m - lcsLength;
        int insertions = n - lcsLength;

        // Total operations needed
        return deletions + insertions;
    }

private:
    int longestCommonSubsequence(string s1, string s2, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build the dp array from bottom up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n]; // Length of LCS
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.minOperations(s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends
