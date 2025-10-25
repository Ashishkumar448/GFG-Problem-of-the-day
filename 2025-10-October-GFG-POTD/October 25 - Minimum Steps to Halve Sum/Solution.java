class Solution {
    public int minOperations(int[] arr) {
        double originalSum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int num : arr) {
            originalSum += num;
            pq.add((double) num);
        }
        
        double target = originalSum / 2.0;
        double currentSum = originalSum;
        int operations = 0;
        
        while (currentSum > target) {
            double largest = pq.poll();
            double half = largest / 2.0;
            currentSum -= half;
            pq.add(half);
            operations++;
        }
        
        return operations;
    }
}
