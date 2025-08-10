class Solution {
public:
    int countPS(string s) {
        int n = s.size();
        int count = 0;

        for (int center = 0; center < n; center++) {
            count += expandFromCenter(s, center, center);     // odd length
            count += expandFromCenter(s, center, center + 1); // even length
        }

        return count;
    }

private:
    int expandFromCenter(const string &s, int left, int right) {
        int cnt = 0;
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 >= 2) {
                cnt++;
            }
            left--;
            right++;
        }
        return cnt;
    }
};
