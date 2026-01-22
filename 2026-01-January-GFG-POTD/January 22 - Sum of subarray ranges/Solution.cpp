#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        long long sumMin = getSum(arr, true);
        long long sumMax = getSum(arr, false);
        return (int)(sumMax - sumMin);
    }

private:
    long long getSum(vector<int>& arr, bool isMin) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller / greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                  (isMin ? arr[st.top()] > arr[i]
                         : arr[st.top()] < arr[i])) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller / greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                  (isMin ? arr[st.top()] >= arr[i]
                         : arr[st.top()] <= arr[i])) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }
        return sum;
    }
};
