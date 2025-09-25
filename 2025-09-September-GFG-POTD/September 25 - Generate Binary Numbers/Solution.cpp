#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            result.push_back(bitset<32>(i).to_string().substr(bitset<32>(i).to_string().find('1')));
        }
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 6;
    vector<string> ans = sol.generateBinary(n);
    for (string &s : ans) {
        cout << s << " ";
    }
    return 0;
}
