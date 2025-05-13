#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        vector<int> dp(r + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, r); j > 0; --j) {
                dp[j] = dp[j] + dp[j - 1]; // Use % MOD if required
            }
        }

        return dp[r];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.nCr(n, r) << endl;
        cout << "~" << endl;
    }
    return 0;
}
