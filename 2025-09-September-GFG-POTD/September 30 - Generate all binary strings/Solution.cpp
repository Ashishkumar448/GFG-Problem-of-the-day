#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> result;
        int total = 1 << n; // 2^n
        for (int i = 0; i < total; i++) {
            string binary = "";
            int num = i;
            // Convert number to binary (padded)
            for (int j = n - 1; j >= 0; j--) {
                binary += ((num >> j) & 1) ? '1' : '0';
            }
            result.push_back(binary);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.binstr(3);
    for (auto &s : res) cout << s << " ";
    return 0;
}
