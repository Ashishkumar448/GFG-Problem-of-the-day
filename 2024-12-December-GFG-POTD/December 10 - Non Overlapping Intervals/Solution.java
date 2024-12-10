// Sort intervals based on their end times
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int count = 0;  // Count of intervals to remove
        int prevEnd = Integer.MIN_VALUE;  // End of the last added interval

        for (int[] interval : intervals) {
            // If the current interval starts before the previous one ends, overlap occurs
            if (interval[0] < prevEnd) {
                count++;
            } else {
                // Update the end to the current interval's end
                prevEnd = interval[1];
            }
        }

        return count;
