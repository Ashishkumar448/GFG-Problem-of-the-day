class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            int val = mat[row][col];

            if (val == x) return true;

            int lowVal = mat[low / m][low % m];
            int highVal = mat[high / m][high % m];

            // Left half sorted
            if (lowVal <= val) {
                if (x >= lowVal && x < val) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (x > val && x <= highVal) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
