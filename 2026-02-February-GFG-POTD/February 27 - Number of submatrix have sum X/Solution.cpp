class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Step 1: Create prefix sum matrix
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }
        
        int count = 0;
        
        // Step 2: Try all possible square sizes
        for (int size = 1; size <= min(n, m); size++) {
            for (int i = size; i <= n; i++) {
                for (int j = size; j <= m; j++) {
                    
                    int sum = prefix[i][j]
                            - prefix[i - size][j]
                            - prefix[i][j - size]
                            + prefix[i - size][j - size];
                    
                    if (sum == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
