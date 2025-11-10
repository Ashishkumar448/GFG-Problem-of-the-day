class Solution {
    public int maxProfit(int arr[]) {
        if (arr == null || arr.length == 0) return 0;
        
        int n = arr.length;
        int hold = -arr[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < n; i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;

            hold = Math.max(prevHold, prevRest - arr[i]);
            sold = prevHold + arr[i];
            rest = Math.max(prevRest, prevSold);
        }

        return Math.max(sold, rest); // final profit (can’t end while holding)
    }
}
