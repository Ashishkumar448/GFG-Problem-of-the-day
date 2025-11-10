class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int n = arr.size();
        int hold = -arr[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < n; i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;

            hold = max(prevHold, prevRest - arr[i]);
            sold = prevHold + arr[i];
            rest = max(prevRest, prevSold);
        }

        return max(sold, rest);
    }
};
