// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Stack to store opening brackets
        stack<char> s;
        
        // Traverse each character in the string
        for (int i = 0; i < x.length(); i++) {
            char ch = x[i];
            
            // If the character is an opening bracket, push it to the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            } 
            // If the character is a closing bracket
            else if (ch == ')' || ch == '}' || ch == ']') {
                // If stack is empty, return false (no matching opening bracket)
                if (s.empty()) {
                    return false;
                }
                
                // Pop the top element and check if it matches the current closing bracket
                char top = s.top();
                s.pop();
                
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // If the stack is empty, it means all opening brackets were matched
        return s.empty();
    }
};

// { Driver Code Starts
int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        string st;
        cin >> st;
        
        Solution obj;
        if(obj.ispar(st)) {
            cout << "balanced" << endl;
        } else {
            cout << "not balanced" << endl;
        }
    }
    
    return 0;
}
// } Driver Code Ends
