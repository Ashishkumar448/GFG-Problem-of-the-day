class Solution {
public:
    vector<vector<string>> palinParts(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (isPalindrome(substring)) {
                current.push_back(substring);
                backtrack(s, end, current, result);
                current.pop_back();  // backtrack
            }
        }
    }

    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--])
                return false;
        }
        return true;
    }
};
