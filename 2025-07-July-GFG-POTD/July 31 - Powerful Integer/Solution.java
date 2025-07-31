class Solution {
    public int powerfulInteger(int[][] intervals, int k) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        // Mark the start and end+1 of each interval
        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            map.put(start, map.getOrDefault(start, 0) + 1);
            map.put(end + 1, map.getOrDefault(end + 1, 0) - 1);
        }

        int curr = 0;
        int lastPoint = -1;
        int maxPowerful = -1;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int point = entry.getKey();
            if (curr >= k && lastPoint != -1) {
                // All integers from lastPoint to point - 1 are powerful
                maxPowerful = Math.max(maxPowerful, point - 1);
            }

            curr += entry.getValue();
            lastPoint = point;
        }

        return maxPowerful;
    }
}
