class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp_len(n, 1);
        vector<int> dp_sum(n);

        for (int i = 0; i < n; ++i) {
            dp_sum[i] = arr[i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    if (dp_len[j] + 1 > dp_len[i]) {
                        dp_len[i] = dp_len[j] + 1;
                        dp_sum[i] = dp_sum[j] + arr[i];
                    } else if (dp_len[j] + 1 == dp_len[i]) {
                        dp_sum[i] = min(dp_sum[i], dp_sum[j] + arr[i]);
                    }
                }
            }
        }

        int maxLen = 0;
        int minSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dp_len[i] > maxLen) {
                maxLen = dp_len[i];
                minSum = dp_sum[i];
            } else if (dp_len[i] == maxLen) {
                minSum = min(minSum, dp_sum[i]);
            }
        }

        int totalSum = 0;
        for (int val : arr) {
            totalSum += val;
        }

        return totalSum - minSum;
    }
};
