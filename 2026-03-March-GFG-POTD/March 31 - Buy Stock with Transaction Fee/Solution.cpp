class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        int hold = -arr[0]; // Buying on day 0
        int cash = 0;       // No stock in hand

        for (int i = 1; i < n; i++) {
            int prevCash = cash;

            // Sell stock today
            cash = max(cash, hold + arr[i] - k);

            // Buy stock today
            hold = max(hold, prevCash - arr[i]);
        }

        return cash;
    }
};
