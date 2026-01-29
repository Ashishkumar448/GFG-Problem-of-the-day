#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstNonRepeating(string s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string result = "";

        for (char ch : s) {
            // Update frequency
            freq[ch - 'a']++;

            // Add current character to queue
            q.push(ch);

            // Remove repeating characters from front
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            // Append result for current prefix
            if (q.empty()) {
                result.push_back('#');
            } else {
                result.push_back(q.front());
            }
        }

        return result;
    }
};
