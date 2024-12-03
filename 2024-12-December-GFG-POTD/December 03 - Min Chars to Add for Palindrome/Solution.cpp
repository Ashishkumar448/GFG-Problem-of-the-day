#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static int minChar(string s) {
        // Concatenate original string, $, and reversed string
        string concatenated = s + "$" + string(s.rbegin(), s.rend());
        int n = concatenated.length();

        // Build LPS array
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; ) {
            if (concatenated[i] == concatenated[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Length of the longest palindromic suffix in original string
        int longestPalindromicSuffix = lps[n - 1];
        
        // Minimum characters to add at the front
        return s.length() - longestPalindromicSuffix;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << Solution::minChar(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
