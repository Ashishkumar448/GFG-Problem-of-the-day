class Solution {
    public int kBitFlips(int[] arr, int k) {
        int n = arr.length;
        int res = 0;
        int flipCount = 0;
        int[] isFlipped = new int[n];  // to track when a flip effect ends

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipCount ^= isFlipped[i - k]; // remove the effect of flip that expired
            }

            // if current bit (after considering flips) is 0, we must flip
            if ((arr[i] ^ flipCount) == 0) {
                if (i + k > n) return -1; // can't flip beyond bounds
                res++;
                flipCount ^= 1;  // new flip starts here
                isFlipped[i] = 1;  // mark start of flip
            }
        }

        return res;
    }
}
