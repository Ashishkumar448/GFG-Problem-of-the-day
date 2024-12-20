//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>> mat, int r, int c) {
        vector<int> result;
        int top = 0, bottom = r - 1, left = 0, right = c - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--;

            // Traverse from right to left, if rows are remaining
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top, if columns are remaining
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> mat(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.spirallyTraverse(mat, r, c);
        for (int val : ans) cout << val << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
