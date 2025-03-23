#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string digits) {
        if (digits.empty() || digits[0] == '0') return 0;

        int n = digits.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // Check single digit
            if (digits[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Check two digits
            int twoDigits = stoi(digits.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string digits;
        cin >> digits;
        Solution ob;
        int ans = ob.countWays(digits);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
