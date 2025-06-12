class Solution {
    int[] printKClosest(int[] arr, int k, int x) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> {
                int distA = Math.abs(a[0] - x);
                int distB = Math.abs(b[0] - x);
                if (distA == distB) {
                    return a[0] - b[0]; // smaller comes first, so larger gets popped
                }
                return distB - distA; // max-heap by distance
            }
        );
        
        for (int val : arr) {
            if (val == x) continue;
            maxHeap.offer(new int[]{val});
            if (maxHeap.size() > k) {
                maxHeap.poll(); // remove the least close
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!maxHeap.isEmpty()) {
            result.add(maxHeap.poll()[0]);
        }

        // Sort by closeness
        result.sort((a, b) -> {
            int distA = Math.abs(a - x);
            int distB = Math.abs(b - x);
            if (distA == distB) return b - a; // prefer larger element
            return distA - distB;
        });

        // Convert to array
        int[] resArr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resArr[i] = result.get(i);
        }
        return resArr;
    }
}
