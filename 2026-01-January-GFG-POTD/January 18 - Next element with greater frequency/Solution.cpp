class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);

        // Step 1: Frequency map
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Stack to store indices
        stack<int> st;

        // Step 3: Traverse array
        for (int i = 0; i < n; i++) {
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
