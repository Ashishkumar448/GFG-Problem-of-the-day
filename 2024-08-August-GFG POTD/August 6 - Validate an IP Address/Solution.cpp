// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // Split the string by "."
        vector<string> parts;
        stringstream ss(str);
        string part;

        while (getline(ss, part, '.')) {
            parts.push_back(part);
        }

        // Check if the IP address has exactly 4 parts
        if (parts.size() != 4) {
            return 0;
        }

        for (const string& part : parts) {
            // Check if the part is not empty
            if (part.empty()) {
                return 0;
            }

            // Check if the part is a valid integer and within the range [0, 255]
            for (char ch : part) {
                if (!isdigit(ch)) {
                    return 0;
                }
            }

            try {
                int num = stoi(part);
                if (num < 0 || num > 255) {
                    return 0;
                }
            } catch (...) {
                return 0; // The part is not a valid integer
            }
        }

        return 1;
    }
};

// { Driver Code Starts
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << (obj.isValid(s) ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends
