#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string s) {
        int n = s.length();
        int m = (n + 1) / 2; // Number of symbols (T/F)
        if (m == 0) return 0;

        vector<vector<long>> T(m, vector<long>(m, 0)); // True counts
        vector<vector<long>> F(m, vector<long>(m, 0)); // False counts

        // Base case: single symbol
        for (int i = 0; i < m; i++) {
            if (s[2 * i] == 'T') {
                T[i][i] = 1;
                F[i][i] = 0;
            } else {
                T[i][i] = 0;
                F[i][i] = 1;
            }
        }

        // Fill DP tables
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i <= m - len; i++) {
                int j = i + len - 1;
                T[i][j] = 0;
                F[i][j] = 0;

                for (int k = i; k < j; k++) {
                    char op = s[2 * k + 1];
                    long leftT = T[i][k], leftF = F[i][k];
                    long rightT = T[k + 1][j], rightF = F[k + 1][j];

                    if (op == '&') {
                        T[i][j] += leftT * rightT;
                        F[i][j] += leftT * rightF + leftF * rightT + leftF * rightF;
                    } else if (op == '|') {
                        T[i][j] += leftT * rightT + leftT * rightF + leftF * rightT;
                        F[i][j] += leftF * rightF;
                    } else if (op == '^') {
                        T[i][j] += leftT * rightF + leftF * rightT;
                        F[i][j] += leftT * rightT + leftF * rightF;
                    }
                }
            }
        }

        return T[0][m - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.countWays(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}
