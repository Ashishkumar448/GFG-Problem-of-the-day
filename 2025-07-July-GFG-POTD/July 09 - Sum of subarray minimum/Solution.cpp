class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> prevLess(n), nextLess(n);
        stack<int> s;

        // Previous Less
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prevLess[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack
        while (!s.empty()) s.pop();

        // Next Less
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nextLess[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;
            sum = (sum + arr[i] * left * right) % MOD;
        }

        return (int)sum;
    }
};
