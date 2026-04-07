#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();

        vector<int> wifeOfMan(n, -1);
        vector<int> husbandOfWoman(n, -1);
        vector<int> nextProposal(n, 0);

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]];
            nextProposal[m]++;

            if (husbandOfWoman[w] == -1) {
                // Woman is free
                husbandOfWoman[w] = m;
                wifeOfMan[m] = w;
            } else {
                int currentMan = husbandOfWoman[w];

                if (rank[w][m] < rank[w][currentMan]) {
                    // Woman prefers new man
                    husbandOfWoman[w] = m;
                    wifeOfMan[m] = w;

                    // Old man becomes free
                    wifeOfMan[currentMan] = -1;
                    freeMen.push(currentMan);
                } else {
                    // Woman rejects proposal
                    freeMen.push(m);
                }
            }
        }

        return wifeOfMan;
    }
};
