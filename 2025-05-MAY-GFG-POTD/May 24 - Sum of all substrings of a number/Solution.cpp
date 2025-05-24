class Solution {
public:
    static int sumSubstrings(string s) {
        int n = s.length();
        long long res = 0;
        long long prev = 0;

        for (int i = 0; i < n; ++i) {
            int num = s[i] - '0';
            prev = prev * 10 + (long long)num * (i + 1);
            res += prev;
        }

        return (int)res;
    }
};
