#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPS(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Checking substrings of length 1 (ignored in count)
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Checking substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }

        // Checking substrings of length ≥3
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.countPS(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
