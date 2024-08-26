#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int wildCard(string pattern, string str) {
        int n = str.length();
        int m = pattern.length();

        // Create a DP table with default value false
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty pattern can match with empty string
        dp[0][0] = true;

        // Only '*' can match with empty string
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[j - 1] == '*') {
                    // '*' can match with or without the current character of str
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1]) {
                    // '?' or exact match
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        // Return the result
        return dp[n][m] ? 1 : 0;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string pat, text;
        getline(cin, pat);
        getline(cin, text);
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
    return 0;
}
