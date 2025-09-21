#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j]++;
            }

            // largest rectangle in histogram
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int h = (j == m ? 0 : heights[j]);
                while (!st.empty() && h < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                st.push(j);
            }
        }
        return maxArea;
    }
};

// Example usage:
// int main() {
//     vector<vector<int>> mat = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
//     Solution sol;
//     cout << sol.maxArea(mat) << endl; // Output: 8
// }
