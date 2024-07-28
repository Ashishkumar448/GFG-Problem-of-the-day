//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string removeDups(string str) {
        unordered_set<char> seen;
        string result;
        for (char c : str) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                result += c;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        string result = ob.removeDups(s);

        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
