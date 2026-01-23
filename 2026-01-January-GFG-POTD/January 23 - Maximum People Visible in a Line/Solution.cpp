class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);

        stack<pair<int,int>> st;

        // LEFT VISIBILITY
        for (int i = 0; i < n; i++) {
            int count = 0;

            while (!st.empty() && st.top().first < arr[i]) {
                count += st.top().second;
                st.pop();
            }

            left[i] = count;
            st.push({arr[i], count + 1});
        }

        while (!st.empty()) st.pop();

        // RIGHT VISIBILITY
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;

            while (!st.empty() && st.top().first < arr[i]) {
                count += st.top().second;
                st.pop();
            }

            right[i] = count;
            st.push({arr[i], count + 1});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i] + 1);
        }

        return ans;
    }
};
