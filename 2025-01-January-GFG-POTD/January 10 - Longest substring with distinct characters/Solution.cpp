#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUniqueSubstr(string s) {
        if (s.empty()) return 0;

        unordered_map<char, int> lastSeen;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            // If the character is already in the map, update the start index
            if (lastSeen.find(currentChar) != lastSeen.end()) {
                start = max(start, lastSeen[currentChar] + 1);
            }

            // Update the last seen index of the current character
            lastSeen[currentChar] = end;

            // Calculate the current window length and update maxLength
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestUniqueSubstr(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
