#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStringChain(vector<string>& words) {
        // Sort words based on length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int maxChain = 1;

        for (string word : words) {
            int longest = 1; // A word itself is a chain of length 1

            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.find(prev) != dp.end()) {
                    longest = max(longest, dp[prev] + 1);
                }
            }

            dp[word] = longest;
            maxChain = max(maxChain, longest);
        }

        return maxChain;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++) cin >> words[i];

        Solution obj;
        cout << obj.longestStringChain(words) << endl;
    }
    return 0;
}
