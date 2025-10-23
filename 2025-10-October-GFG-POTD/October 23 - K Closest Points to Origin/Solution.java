class Solution {
    public ArrayList<ArrayList<Integer>> kClosest(int[][] points, int k) {
        // Max-Heap that stores [distance, index]
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b[0], a[0])  // sort by distance descending
        );

        for (int i = 0; i < points.length; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y; // distance squared

            maxHeap.offer(new int[]{dist, i});
            if (maxHeap.size() > k) {
                maxHeap.poll(); // remove the farthest point
            }
        }

        // Collect k closest points
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        while (!maxHeap.isEmpty()) {
            int index = maxHeap.poll()[1];
            ArrayList<Integer> point = new ArrayList<>();
            point.add(points[index][0]);
            point.add(points[index][1]);
            result.add(point);
        }

        return result;
    }
}
