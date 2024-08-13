//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& M, int n) {
        int candidate = 0;

        // Step 1: Find the candidate
        for (int i = 1; i < n; i++) {
            if (M[candidate][i] == 1) {
                candidate = i;
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.celebrity(M, n) << endl;
    }
    return 0;
}
// } Driver Code Ends