#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maxLength(string S) {
        // Stack to store the indices of the characters
        stack<int> st;
        // Initialize the stack with -1 to handle edge cases
        st.push(-1);
        int maxLen = 0;
        
        // Traverse through the string
        for (int i = 0; i < S.length(); i++) {
            char c = S[i];
            
            // If it's an opening parenthesis, push its index onto the stack
            if (c == '(') {
                st.push(i);
            }
            // If it's a closing parenthesis
            else {
                // Pop the top index
                st.pop();
                
                // If the stack is not empty, calculate the length of the valid substring
                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } 
                // If the stack is empty, push the current index as a new base
                else {
                    st.push(i);
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
    }
    return 0;
}
