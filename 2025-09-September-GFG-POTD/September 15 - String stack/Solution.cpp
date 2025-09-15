class Solution {
public:
    bool stringStack(string pat, string tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                // use pat[i] to match tar[j]
                i--;
                j--;
            } else {
                // use pat[i] as delete -> skips previous appended char
                i -= 2;
            }
        }
        // matched all chars of tar?
        return j < 0;
    }
};
