class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int minLen = INT_MAX;
        int startIndex = -1;

        int i = 0;
        while (i < n) {
            int j = 0;

            // Move forward to match s2 as subsequence
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            if (i == n) break;

            // Shrink backwards
            int end = i;
            j = m - 1;

            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            int start = i;
            int windowLen = end - start + 1;

            if (windowLen < minLen) {
                minLen = windowLen;
                startIndex = start;
            }

            i = start + 1;
        }

        return startIndex == -1 ? "" : s1.substr(startIndex, minLen);
    }
};
