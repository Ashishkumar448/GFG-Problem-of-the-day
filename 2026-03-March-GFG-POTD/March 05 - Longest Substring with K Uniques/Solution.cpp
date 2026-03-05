class Solution {
public:
    int longestKSubstr(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int distinct = 0;
        int maxLen = -1;

        while (right < s.length()) {
            char c = s[right];
            if (freq[c - 'a'] == 0)
                distinct++;

            freq[c - 'a']++;

            while (distinct > k) {
                char leftChar = s[left];
                freq[leftChar - 'a']--;

                if (freq[leftChar - 'a'] == 0)
                    distinct--;

                left++;
            }

            if (distinct == k)
                maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};
