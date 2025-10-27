class Solution {
    public ArrayList<ArrayList<Integer>> kSmallestPair(int[] arr1, int[] arr2, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        if (arr1.length == 0 || arr2.length == 0 || k == 0) return result;

        // Min-heap to store (sum, i, j)
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(a[0], b[0])
        );

        // Initialize heap with first element of arr2 for each arr1[i]
        for (int i = 0; i < Math.min(arr1.length, k); i++) {
            minHeap.offer(new int[]{arr1[i] + arr2[0], i, 0});
        }

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            int i = top[1], j = top[2];

            // Add the pair [arr1[i], arr2[j]]
            ArrayList<Integer> pair = new ArrayList<>();
            pair.add(arr1[i]);
            pair.add(arr2[j]);
            result.add(pair);

            // If possible, add the next pair with arr2[j + 1]
            if (j + 1 < arr2.length) {
                minHeap.offer(new int[]{arr1[i] + arr2[j + 1], i, j + 1});
            }
        }

        return result;
    }
}
