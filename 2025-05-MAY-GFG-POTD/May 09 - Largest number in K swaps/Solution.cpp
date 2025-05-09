#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maxStr;

    string findMaximumNum(string str, int k) {
        maxStr = str;
        findMaxHelper(str, k, 0);
        return maxStr;
    }

private:
    void findMaxHelper(string &s, int k, int idx) {
        if (k == 0 || idx == s.length()) return;

        char maxDigit = s[idx];
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        if (maxDigit != s[idx]) {
            for (int i = s.length() - 1; i > idx; i--) {
                if (s[i] == maxDigit) {
                    swap(s[idx], s[i]);
                    if (s > maxStr) {
                        maxStr = s;
                    }

                    findMaxHelper(s, k - 1, idx + 1);
                    swap(s[idx], s[i]); // backtrack
                }
            }
        } else {
            findMaxHelper(s, k, idx + 1);
        }
    }
};

// Example usage (replace with proper test cases as needed):
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string str;
        cin >> k >> str;
        Solution obj;
        cout << obj.findMaximumNum(str, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
