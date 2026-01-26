class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        backtrack(arr, 0, res);
        return res;
    }

private:
    void backtrack(vector<int>& arr, int idx, vector<vector<int>>& res) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            swap(arr[i], arr[idx]);
            backtrack(arr, idx + 1, res);
            swap(arr[i], arr[idx]); // backtrack
        }
    }
};
