#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        int inf = 100000000;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < inf && dist[k][j] < inf && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];

        Solution obj;
        obj.floydWarshall(matrix);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
