#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool matSearch(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Start from the top-right corner
        int row = 0, col = m - 1;
        
        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; // Found the element
            } else if (mat[row][col] > x) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }
        
        return false; // Element not found
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        
        int x;
        cin >> x;
        
        Solution sol;
        if (sol.matSearch(mat, x))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        
        cout << "~" << endl;
    }
    return 0;
}
