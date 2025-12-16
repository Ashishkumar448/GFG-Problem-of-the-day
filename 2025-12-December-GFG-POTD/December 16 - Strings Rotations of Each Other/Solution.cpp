class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2) {
        // 1. Basic Length Check
        if (s1.length() != s2.length()) {
            return false;
        }

        int n = s1.length();
        if (n == 0) return true;

        // 2. Compute LPS (Longest Prefix Suffix) array for s2 (the pattern)
        // We use vector<int> for dynamic size management
        vector<int> lps(n, 0);
        int len = 0; 
        int i = 1;

        while (i < n) {
            if (s2[i] == s2[len]) {
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

        // 3. KMP Search on virtual (s1 + s1)
        int j = 0; // index for s2
        i = 0;     // index for s1 (virtual traversal)

        while (i < 2 * n) {
            // Compare s2[j] with s1[i % n] using modulo to wrap around
            if (s2[j] == s1[i % n]) {
                j++;
                i++;
                // If we have matched the entire s2 string
                if (j == n) {
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
};
