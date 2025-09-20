#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextGreater(n, n);
        vector<int> prevGreater(n, -1);
        stack<int> st;

        // Next Greater Element to the Right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Clear stack for prev greater
        while (!st.empty()) st.pop();

        // Next Greater Element to the Left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            int windowSize = nextGreater[i] - prevGreater[i] - 1;
            if (windowSize >= arr[i]) {
                maxLength = max(maxLength, windowSize);
            }
        }
        return maxLength;
    }
};

// Example usage
int main() {
    vector<int> arr = {2, 2, 3, 15, 8, 11, 6, 6};
    cout << Solution::longestSubarray(arr) << endl; // Expected 3
    return 0;
}
