#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> span;
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            // Pop while current price is higher or equal
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            int currSpan = st.empty() ? i + 1 : i - st.top();
            span.push_back(currSpan);

            // Push current index
            st.push(i);
        }

        return span;
    }
};
