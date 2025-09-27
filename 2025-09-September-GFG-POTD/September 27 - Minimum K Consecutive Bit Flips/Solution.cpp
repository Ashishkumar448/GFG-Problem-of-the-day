class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int res = 0;
        int flipCount = 0;
        vector<int> isFlipped(n, 0);  // to track when a flip effect ends

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipCount ^= isFlipped[i - k]; // remove expired flip
            }

            if ((arr[i] ^ flipCount) == 0) { // need to flip
                if (i + k > n) return -1;
                res++;
                flipCount ^= 1;   // start new flip
                isFlipped[i] = 1; // mark flip start
            }
        }
        return res;
    }
};
