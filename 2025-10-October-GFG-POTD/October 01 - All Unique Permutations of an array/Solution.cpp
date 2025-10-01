#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        vector<int> current;
        vector<bool> used(arr.size(), false);
        backtrack(arr, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& arr, vector<bool>& used, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == arr.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;

            // Skip duplicates
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(arr[i]);
            backtrack(arr, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
};

// Example usage
// int main() {
//     Solution sol;
//     vector<int> arr = {1, 3, 3};
//     auto res = sol.uniquePerms(arr);
//     for (auto &perm : res) {
//         for (int num : perm) cout << num << " ";
//         cout << endl;
//     }
// }
