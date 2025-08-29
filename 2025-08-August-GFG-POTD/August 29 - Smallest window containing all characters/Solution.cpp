#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string smallestWindow(string s, string p) {
        if (s.size() < p.size()) return "";

        // frequency map for p
        vector<int> freqP(26, 0);
        for (char c : p) {
            freqP[c - 'a']++;
        }

        vector<int> freqS(26, 0);
        int count = 0; 
        int required = p.size();

        int minLen = INT_MAX;
        int minStart = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            freqS[c - 'a']++;

            if (freqP[c - 'a'] > 0 && freqS[c - 'a'] <= freqP[c - 'a']) {
                count++;
            }

            while (count == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                freqS[leftChar - 'a']--;

                if (freqP[leftChar - 'a'] > 0 && freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                    count--;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
