class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int candidate = 0;

        // Step 1: Find a potential celebrity
        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1) {
                // candidate knows i → candidate can't be celebrity
                candidate = i;
            }
            // else i cannot be celebrity
        }

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Candidate should not know i, and everyone should know candidate
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
