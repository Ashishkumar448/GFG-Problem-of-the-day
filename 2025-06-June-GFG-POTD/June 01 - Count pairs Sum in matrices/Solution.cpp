#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int x) {
        int n = mat1.size();
        unordered_set<int> s;

        // Step 1: Add all elements from mat2 to the set
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                s.insert(mat2[i][j]);
            }
        }

        int count = 0;

        // Step 2: Check for each element in mat1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = mat1[i][j];
                int b = x - a;
                if (s.count(b)) {
                    count++;
                }
            }
        }

        return count;
    }
};
