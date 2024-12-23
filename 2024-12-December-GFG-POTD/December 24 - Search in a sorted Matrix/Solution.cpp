// { Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int rows = mat.size();
        int cols = mat[0].size();

        int i = 0; // Start from the first row
        int j = cols - 1; // Start from the last column

        // Traverse the matrix
        while (i < rows && j >= 0) {
            if (mat[i][j] == x) {
                return true; // Target found
            } else if (mat[i][j] > x) {
                j--; // Move left
            } else {
                i++; // Move down
            }
        }

        return false; // Target not found
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int rows, columns;
        cin >> rows >> columns;

        vector<vector<int>> matrix(rows, vector<int>(columns));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
        }

        int target;
        cin >> target;

        Solution obj;
        if (obj.searchMatrix(matrix, target))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
