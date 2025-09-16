#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        
        for (string& token : arr) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();  // right operand
                int a = st.top(); st.pop();  // left operand
                int result = 0;
                
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") {
                    // floor division handling
                    result = (int)floor((double)a / b);
                } 
                else if (token == "^") result = (int)pow(a, b);
                
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
    
private:
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
    }
};
