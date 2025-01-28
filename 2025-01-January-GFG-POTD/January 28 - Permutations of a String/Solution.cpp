#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> result;
        sort(s.begin(), s.end()); // Sort to handle duplicates easily
        vector<bool> used(s.size(), false);
        string current;
        backtrack(result, current, s, used);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, const string& s, vector<bool>& used) {
        if (current.length() == s.length()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            // Skip already used characters
            if (used[i]) continue;

            // Skip duplicates (only use the first occurrence)
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            // Mark the character as used
            used[i] = true;
            current.push_back(s[i]);

            // Recursive call
            backtrack(result, current, s, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution obj;
        vector<string> ans = obj.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (const string& str : ans) {
            cout << str << " ";
        }
        cout << endl << "~" << endl;
    }
    return 0;
}
