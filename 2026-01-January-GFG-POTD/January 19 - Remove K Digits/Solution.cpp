#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdig(string s, int k) {
        stack<char> st;

        for (char c : s) {
            // Remove larger digits from stack if possible
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If k digits still need to be removed, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result string
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < result.size() && result[idx] == '0') {
            idx++;
        }

        result = result.substr(idx);

        // If empty, return "0"
        return result.empty() ? "0" : result;
    }
};
