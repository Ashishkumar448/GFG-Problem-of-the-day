#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n;
            while (!st.empty() && arr[st.top()] <= arr[index]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    res[index] = arr[st.top()];
                }
            }
            st.push(index);
        }
        return res;
    }
};
