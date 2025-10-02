#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, temp, n, k, 1, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& temp, 
                   int target, int k, int start, int sum) {
        if (temp.size() == k) {
            if (sum == target) {
                result.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (sum + i > target) break; // pruning
            temp.push_back(i);
            backtrack(result, temp, target, k, i + 1, sum + i);
            temp.pop_back();
        }
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     auto ans = sol.combinationSum(9, 3);
//     for (auto &vec : ans) {
//         for (int x : vec) cout << x << " ";
//         cout << endl;
//     }
// }
