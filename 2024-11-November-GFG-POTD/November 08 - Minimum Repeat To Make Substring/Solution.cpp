#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void computeLPSArray(string s, vector<int>& lps) {
        int len = 0;
        int idx = 1;
        lps[0] = 0;

        while (idx < s.length()) {
            if (s[idx] == s[len]) {
                len++;
                lps[idx] = len;
                idx++;
            } else {
                if (len == 0) {
                    lps[idx] = 0;
                    idx++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
    }

    bool KMPSearch(const string& txt, const string& pat, const vector<int>& lps, int rep) {
        int n = txt.length(), m = pat.length();
        int i = 0, j = 0;

        while (i < n * rep) {
            if (txt[i % n] == pat[j]) {
                i++;
                j++;

                if (j == m) {
                    return true;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    int minRepeats(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<int> lps(m, 0);
        computeLPSArray(s2, lps);

        int x = (m + n - 1) / n;

        if (KMPSearch(s1, s2, lps, x)) return x;

        if (KMPSearch(s1, s2, lps, x + 1)) return x + 1;

        return -1;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
