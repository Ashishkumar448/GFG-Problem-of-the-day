#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        for (int i = 0; i < mat.size(); i++) {
            // Apply binary search on each row
            if (binarySearch(mat[i], x)) {
                return true;
            }
        }
        return false;
    }

private:
    bool binarySearch(vector<int>& row, int x) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == x) {
                return true;
            } else if (row[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
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

        Solution solution;
        if (solution.searchRowMatrix(matrix, target))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
