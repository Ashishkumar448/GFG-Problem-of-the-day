#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& matrix) {
        vector<int> result;
        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Top row
            for (int j = startCol; j <= endCol; j++) {
                result.push_back(matrix[startRow][j]);
            }
            startRow++;

            // Right column
            for (int i = startRow; i <= endRow; i++) {
                result.push_back(matrix[i][endCol]);
            }
            endCol--;

            // Bottom row
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    result.push_back(matrix[endRow][j]);
                }
                endRow--;
            }

            // Left column
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    result.push_back(matrix[i][startCol]);
                }
                startCol++;
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
        vector<vector<int>> matrix(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.spirallyTraverse(matrix);
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
