class Solution {
    public ArrayList<Integer> minMaxCandy(int[] prices, int k) {
        Arrays.sort(prices);
        int n = prices.length;
        
        // Calculate min cost
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i];
            i++;
            j -= k; // take k most expensive ones for free
        }
        
        // Calculate max cost
        int maxCost = 0;
        i = 0;
        j = n - 1;
        while (i <= j) {
            maxCost += prices[j];
            j--;
            i += k; // take k cheapest ones for free
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(minCost);
        ans.add(maxCost);
        return ans;
    }
}
