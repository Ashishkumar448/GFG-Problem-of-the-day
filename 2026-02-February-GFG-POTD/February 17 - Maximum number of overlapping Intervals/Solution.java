class Solution {
    public static int overlapInt(int[][] arr) {
        int n = arr.length;
        
        List<int[]> events = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            events.add(new int[]{arr[i][0], 1});      // start
            events.add(new int[]{arr[i][1] + 1, -1}); // end+1 (inclusive fix)
        }
        
        // Sort by:
        // 1. Time ascending
        // 2. If same time → process -1 before +1
        Collections.sort(events, (a, b) -> {
            if (a[0] == b[0]) 
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });
        
        int current = 0;
        int max = 0;
        
        for (int[] e : events) {
            current += e[1];
            max = Math.max(max, current);
        }
        
        return max;
    }
}
