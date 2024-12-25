#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Flags to determine if first row and column need to be set to zero
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row has a zero
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column has a zero
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns to be zeroed in the first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0; // Mark the row
                    mat[0][j] = 0; // Mark the column
                }
            }
        }

        // Set the matrix cells to zero based on the markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Handle the first row
        if (firstRowZero) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }

        // Handle the first column
        if (firstColZero) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        Solution().setMatrixZeroes(mat);

        for (const auto& row : mat) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
