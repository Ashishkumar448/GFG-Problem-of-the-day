class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (countLessEqual(mat, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
    
private:
    int countLessEqual(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int count = 0;
        int row = n - 1;
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (mat[row][col] <= x) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
};
