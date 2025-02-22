// C++ Implementation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(string s) {
        stack<int> stack;
        stack.push(-1); // Base index for valid substring
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLen = max(maxLen, i - stack.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
        cout << "~" << endl;
    }
    return 0;
}
