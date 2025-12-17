class Solution {
    public ArrayList<int[]> mergeOverlap(int[][] arr) {
        ArrayList<int[]> result = new ArrayList<>();
        
        // Edge case
        if (arr == null || arr.length == 0) {
            return result;
        }

        // Sort intervals by starting time
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        // Initialize first interval
        int start = arr[0][0];
        int end = arr[0][1];

        for (int i = 1; i < arr.length; i++) {
            // If current interval overlaps
            if (arr[i][0] <= end) {
                end = Math.max(end, arr[i][1]);
            } else {
                // No overlap, add previous interval
                result.add(new int[]{start, end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }

        // Add the last interval
        result.add(new int[]{start, end});

        return result;
    }
}
