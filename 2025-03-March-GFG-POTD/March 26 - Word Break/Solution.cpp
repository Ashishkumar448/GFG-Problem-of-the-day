#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, bool> memo;

    bool canBreak(string s) {
        if (s.empty()) return true;
        if (memo.find(s) != memo.end()) return memo[s];

        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix) && canBreak(s.substr(i))) {
                return memo[s] = true;
            }
        }
        return memo[s] = false;
    }

    bool wordBreak(string s, vector<string>& dictionary) {
        wordSet = unordered_set<string>(dictionary.begin(), dictionary.end());
        memo.clear();
        return canBreak(s);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s, line;
        getline(cin, s);
        getline(cin, line);

        vector<string> dictionary;
        string word;
        for (char ch : line) {
            if (ch == ' ') {
                dictionary.push_back(word);
                word.clear();
            } else {
                word += ch;
            }
        }
        if (!word.empty()) dictionary.push_back(word);

        Solution obj;
        cout << (obj.wordBreak(s, dictionary) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}
