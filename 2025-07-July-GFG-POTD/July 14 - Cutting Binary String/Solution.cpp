#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int cuts(string s) {
        int n = s.size();
        unordered_set<string> powerOf5;

        // Generate all powers of 5 in binary up to 2^30
        long long num = 1;
        while (num <= (1LL << 30)) {
            powerOf5.insert(toBinary(num));
            num *= 5;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                string sub = s.substr(j, i - j);
                if (sub[0] == '0') continue; // skip leading zeros
                if (powerOf5.count(sub) && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }

private:
    string toBinary(long long num) {
        string bin = "";
        while (num > 0) {
            bin = char('0' + (num % 2)) + bin;
            num /= 2;
        }
        return bin;
    }
};
