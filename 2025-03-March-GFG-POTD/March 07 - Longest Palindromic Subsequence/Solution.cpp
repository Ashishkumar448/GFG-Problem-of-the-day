#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalinSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Finding LCS between s and its reverse
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.longestPalinSubseq(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
