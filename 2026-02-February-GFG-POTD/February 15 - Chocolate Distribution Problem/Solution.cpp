// User function Template for C++

class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        int n = arr.size();
        
        // Edge case
        if (m == 0 || n == 0 || m > n) {
            return 0;
        }
        
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        // Check every window of size m
        for (int i = 0; i <= n - m; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};
