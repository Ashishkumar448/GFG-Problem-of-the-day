#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> result;
        int m = pat.length();
        int n = txt.length();
        int d = 256; // Alphabet size
        int q = 101; // A prime number
        int h = 1;
        int p = 0; // Hash for pattern
        int t = 0; // Hash for text window

        // Calculate h = pow(d, m-1) % q
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate initial hash values for pattern and text
        for (int i = 0; i < m; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        // Slide over text
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                int j;
                for (j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j])
                        break;
                }
                if (j == m)
                    result.push_back(i + 1); // 1-based indexing
            }

            if (i < n - m) {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;
                if (t < 0)
                    t = t + q;
            }
        }

        return result;
    }
};
