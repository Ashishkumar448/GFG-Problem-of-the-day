class Solution {
public:
    int maxSumIS(int arr[], int n) {

        vector<int> dp(n);

        // Initialize dp with the element itself
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        int maxSum = arr[0];

        // Compute MSIS
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};
