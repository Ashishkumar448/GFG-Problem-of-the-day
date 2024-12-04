#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        // Concatenate s1 with itself
        string concatenated = s1 + s1;

        // Use KMP to check if s2 is a substring of concatenated string
        return kmpSearch(concatenated, s2);
    }

private:
    // KMP algorithm to check if pattern is a substring of text
    bool kmpSearch(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> lps = computeLPSArray(pattern);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // Pattern found
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    // Compute the longest prefix-suffix (LPS) array for the pattern
    vector<int> computeLPSArray(string pattern) {
        int m = pattern.length();
        vector<int> lps(m);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
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
        return lps;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        if (obj.areRotations(s1, s2)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
