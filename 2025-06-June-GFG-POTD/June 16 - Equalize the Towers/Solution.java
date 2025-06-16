class Solution {
    public int minCost(int[] heights, int[] cost) {
        int n = heights.length;

        // Step 1: Pair heights and costs and sort by height
        int[][] towers = new int[n][2];
        for (int i = 0; i < n; i++) {
            towers[i][0] = heights[i];
            towers[i][1] = cost[i];
        }

        Arrays.sort(towers, Comparator.comparingInt(a -> a[0]));

        // Step 2: Extract sorted heights and cost arrays
        int[] sortedHeights = new int[n];
        int[] sortedCost = new int[n];
        for (int i = 0; i < n; i++) {
            sortedHeights[i] = towers[i][0];
            sortedCost[i] = towers[i][1];
        }

        // Step 3: Prefix sums of cost and cost*height
        long[] prefixCost = new long[n];
        long[] prefixCostHeight = new long[n];
        prefixCost[0] = sortedCost[0];
        prefixCostHeight[0] = (long) sortedCost[0] * sortedHeights[0];

        for (int i = 1; i < n; i++) {
            prefixCost[i] = prefixCost[i - 1] + sortedCost[i];
            prefixCostHeight[i] = prefixCostHeight[i - 1] + (long) sortedCost[i] * sortedHeights[i];
        }

        // Step 4: Suffix sums of cost and cost*height
        long[] suffixCost = new long[n];
        long[] suffixCostHeight = new long[n];
        suffixCost[n - 1] = sortedCost[n - 1];
        suffixCostHeight[n - 1] = (long) sortedCost[n - 1] * sortedHeights[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixCost[i] = suffixCost[i + 1] + sortedCost[i];
            suffixCostHeight[i] = suffixCostHeight[i + 1] + (long) sortedCost[i] * sortedHeights[i];
        }

        // Step 5: Try each height as target and calculate the cost
        long minTotalCost = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long costLeft = 0, costRight = 0;
            int targetHeight = sortedHeights[i];

            // Cost to raise left towers to targetHeight
            if (i > 0) {
                costLeft = (long) targetHeight * prefixCost[i - 1] - prefixCostHeight[i - 1];
            }

            // Cost to reduce right towers to targetHeight
            if (i < n - 1) {
                costRight = suffixCostHeight[i + 1] - (long) targetHeight * suffixCost[i + 1];
            }

            long totalCost = costLeft + costRight;
            minTotalCost = Math.min(minTotalCost, totalCost);
        }

        return (int) minTotalCost;
    }

}
