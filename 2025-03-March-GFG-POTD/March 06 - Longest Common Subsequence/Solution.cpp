#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lcs(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table using bottom-up approach
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.lcs(s1, s2) << endl;
        cout << "~" << endl;
    }
    return 0;
}
