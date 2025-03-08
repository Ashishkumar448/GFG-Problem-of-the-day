#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, max_len = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expand(s, i, i);      // Odd-length palindromes
            int len2 = expand(s, i, i + 1);  // Even-length palindromes
            int current_len = max(len1, len2);
            
            if (current_len > max_len) {
                max_len = current_len;
                // Calculate start index based on expansion type
                start = (len1 > len2) ? (i - (len1 - 1)/2) : (i - (len2/2 - 1));
            }
        }
        return s.substr(start, max_len);
    }
    
private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Actual palindrome length
    }
};
