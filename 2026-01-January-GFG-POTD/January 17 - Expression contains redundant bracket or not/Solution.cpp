#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRedundancy(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                // Check contents inside parentheses
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                // Remove opening '('
                if (!st.empty())
                    st.pop();

                // No operator found → redundant brackets
                if (!hasOperator)
                    return true;
            } else {
                st.push(ch);
            }
        }

        return false;
    }
};
