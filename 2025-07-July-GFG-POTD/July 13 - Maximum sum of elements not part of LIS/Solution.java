class Solution {
    public int nonLisMaxSum(int[] arr) {
        int n = arr.length;
        int[] dp_len = new int[n];
        int[] dp_sum = new int[n];
        
        for (int i = 0; i < n; i++) {
            dp_len[i] = 1;
            dp_sum[i] = arr[i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (dp_len[j] + 1 > dp_len[i]) {
                        dp_len[i] = dp_len[j] + 1;
                        dp_sum[i] = dp_sum[j] + arr[i];
                    } else if (dp_len[j] + 1 == dp_len[i]) {
                        dp_sum[i] = Math.min(dp_sum[i], dp_sum[j] + arr[i]);
                    }
                }
            }
        }
        
        int maxLen = 0;
        int minSum = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) {
            if (dp_len[i] > maxLen) {
                maxLen = dp_len[i];
                minSum = dp_sum[i];
            } else if (dp_len[i] == maxLen) {
                minSum = Math.min(minSum, dp_sum[i]);
            }
        }
        
        int totalSum = 0;
        for (int val : arr) {
            totalSum += val;
        }
        
        return totalSum - minSum;
    }
}
