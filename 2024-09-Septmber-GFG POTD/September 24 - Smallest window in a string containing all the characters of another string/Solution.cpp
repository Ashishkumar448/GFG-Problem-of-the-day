#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p) {
        if (s.length() < p.length()) {
            return "-1";  // If the length of p is greater than s, no solution exists
        }

        // Frequency maps to store the count of characters in p and the current window in s
        int pFreq[256] = {0};
        int sFreq[256] = {0};

        // Fill frequency map for the pattern string p
        for (char ch : p) {
            pFreq[ch]++;
        }

        // Initialize pointers for the sliding window
        int start = 0, minLen = INT_MAX, count = 0;
        int startIndex = -1;  // To store the starting index of the smallest window

        // Traverse through string s
        for (int end = 0; end < s.length(); end++) {
            // Include the current character in the window
            char ch = s[end];
            sFreq[ch]++;

            // If the current character's frequency in the window is less than or equal to its frequency in p
            if (sFreq[ch] <= pFreq[ch]) {
                count++;
            }

            // When all characters are matched (window is valid)
            if (count == p.length()) {
                // Try to minimize the window by moving the start pointer
                while (sFreq[s[start]] > pFreq[s[start]] || pFreq[s[start]] == 0) {
                    if (sFreq[s[start]] > pFreq[s[start]]) {
                        sFreq[s[start]]--;
                    }
                    start++;
                }

                // Update the minimum window length and the start index of the smallest window
                int windowLen = end - start + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = start;
                }
            }
        }

        // If no valid window was found, return "-1"
        return (startIndex == -1) ? "-1" : s.substr(startIndex, minLen);
    }
};

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s, t;
        cin >> s >> t;

        Solution obj;
        cout << obj.smallestWindow(s, t) << endl;
    }
    return 0;
}
