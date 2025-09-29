class Solution {
     public int maxSubarrSum(int[] arr, int a, int b) {
        int n = arr.length;
        
        // prefix sum array
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // deque stores indices of prefix sums in increasing order
        Deque<Integer> dq = new ArrayDeque<>();
        long ans = Long.MIN_VALUE;

        for (int r = a; r <= n; r++) {
            // Add candidate l = r - a
            int l = r - a;
            while (!dq.isEmpty() && prefix[dq.peekLast()] >= prefix[l]) {
                dq.pollLast();
            }
            dq.offerLast(l);

            // Remove indices out of window (older than r-b)
            while (!dq.isEmpty() && dq.peekFirst() < r - b) {
                dq.pollFirst();
            }

            // Best subarray ending at r-1
            if (!dq.isEmpty()) {
                ans = Math.max(ans, prefix[r] - prefix[dq.peekFirst()]);
            }
        }

        return (int) ans;
    }
}
