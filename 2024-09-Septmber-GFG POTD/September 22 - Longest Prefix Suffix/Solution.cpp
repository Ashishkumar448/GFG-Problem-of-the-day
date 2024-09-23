//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lps(string str) {
        // code here
        int n = str.length();
        vector<int> lpsArray(n);

        int length = 0;  // length of previous longest prefix suffix
        int i = 1;

        // LPS[0] is always 0, no proper prefix or suffix for single character
        lpsArray[0] = 0;

        while (i < n) {
            if (str[i] == str[length]) {
                length++;
                lpsArray[i] = length;
                i++;
            } else {
                if (length != 0) {
                    // Try finding shorter prefix
                    length = lpsArray[length - 1];
                } else {
                    lpsArray[i] = 0;
                    i++;
                }
            }
        }

        // Return the last value in the lpsArray which represents the longest prefix suffix
        return lpsArray[n - 1];
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
        cout << ob.lps(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
