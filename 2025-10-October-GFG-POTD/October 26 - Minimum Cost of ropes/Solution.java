class Solution {
    public static int minCost(int[] arr) {
        if(arr.length <= 1) return 0; // No cost if 0 or 1 rope

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int rope : arr) {
            pq.add(rope);
        }

        int totalCost = 0;

        while(pq.size() > 1) {
            int first = pq.poll();   // Smallest rope
            int second = pq.poll();  // Second smallest rope
            int cost = first + second;
            totalCost += cost;
            pq.add(cost);            // Add new rope back
        }

        return totalCost;
    }
}
