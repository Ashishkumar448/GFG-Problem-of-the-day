#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;

    int numBST(int n) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];

        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += numBST(i - 1) * numBST(n - i);
        }
        memo[n] = total;
        return total;
    }

public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> bstMap;
        for (int i = 0; i < n; ++i) {
            int leftCount = i;
            int rightCount = n - i - 1;
            int count = numBST(leftCount) * numBST(rightCount);
            bstMap[sorted[i]] = count;
        }

        vector<int> result;
        for (int val : arr) {
            result.push_back(bstMap[val]);
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {2, 1, 3};
    vector<int> res = sol.countBSTs(arr);
    for (int x : res) cout << x << " ";
    return 0;
}
