#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        // Traverse the array twice
        for (int i = 0; i < 2 * n; i++) {
            int num = arr[i % n];

            while (!st.empty() && arr[st.top()] < num) {
                int idx = st.top();
                st.pop();
                res[idx] = num;
            }

            // Only push indices in the first pass
            if (i < n) {
                st.push(i);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = sol.nextGreater(arr);

    for (int x : ans) cout << x << " ";
    return 0;
}
