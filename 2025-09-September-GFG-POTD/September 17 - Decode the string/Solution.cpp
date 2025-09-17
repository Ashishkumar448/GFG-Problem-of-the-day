#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // handle multi-digit numbers
            } else if (c == '[') {
                countStack.push(num);
                strStack.push(currStr);
                currStr = "";
                num = 0;
            } else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prevStr = strStack.top(); strStack.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            } else {
                currStr.push_back(c);
            }
        }

        return currStr;
    }
};
