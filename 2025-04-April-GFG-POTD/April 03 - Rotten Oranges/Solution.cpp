#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Step 1: Store all rotten oranges' positions and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        // Step 2: BFS traversal
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                        rotted = true;
                    }
                }
            }

            if (rotted) time++;
        }

        // If any fresh orange is left, return -1
        return freshOranges == 0 ? time : -1;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        cout << obj.orangesRotting(mat) << endl;
        cout << "~" << endl;
    }
    return 0;
}
