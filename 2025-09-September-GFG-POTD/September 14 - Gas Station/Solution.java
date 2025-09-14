class Solution {
    public int startStation(int[] gas, int[] cost) {
        int n = gas.length;
        int total = 0;    // total gas - total cost
        int tank = 0;     // current fuel balance
        int start = 0;    // candidate starting index
        
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            
            // If tank < 0, can't reach station i+1 from current start
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return (total >= 0) ? start : -1;
    }
}
