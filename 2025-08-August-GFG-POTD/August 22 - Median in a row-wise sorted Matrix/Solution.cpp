class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();

        // Find minimum and maximum
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mn = min(mn, mat[i][0]);
            mx = max(mx, mat[i][m - 1]);
        }

        int desired = (n * m + 1) / 2;

        while (mn < mx) {
            int mid = (mn + mx) / 2;
            int count = 0;

            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count < desired)
                mn = mid + 1;
            else
                mx = mid;
        }

        return mn;
    }
};
