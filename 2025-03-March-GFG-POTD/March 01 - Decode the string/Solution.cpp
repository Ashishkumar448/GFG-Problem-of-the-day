#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int num = 0;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Handle multi-digit numbers
            } else if (ch == '[') {
                countStack.push(num);
                stringStack.push(currentString);
                currentString = "";
                num = 0;
            } else if (ch == ']') {
                int repeatCount = countStack.top(); countStack.pop();
                string decodedString = stringStack.top(); stringStack.pop();
                while (repeatCount-- > 0) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += ch;
            }
        }
        
        return currentString;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.decodeString(s) << endl;
    }
    return 0;
}
