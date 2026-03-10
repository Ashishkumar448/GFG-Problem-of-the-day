class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long count = 0;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            int nextSmaller = st.empty() ? n : st.top();
            count += nextSmaller - i;

            st.push(i);
        }

        return (int)count;
    }
};
