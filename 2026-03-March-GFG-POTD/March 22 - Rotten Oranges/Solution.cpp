#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: Add rotten & count fresh
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;
        
        int time = 0;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool rottenThisRound = false;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto &d : dirs) {
                    int ni = x + d[0];
                    int nj = y + d[1];
                    
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && mat[ni][nj] == 1) {
                        mat[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                        rottenThisRound = true;
                    }
                }
            }
            
            if (rottenThisRound) time++;
        }
        
        return (fresh == 0) ? time : -1;
    }
};
