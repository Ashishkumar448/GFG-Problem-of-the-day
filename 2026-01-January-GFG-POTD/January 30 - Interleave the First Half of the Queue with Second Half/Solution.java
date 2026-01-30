class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        int n = q.size();
        
        // Queue to store first half
        Queue<Integer> firstHalf = new LinkedList<>();
        
        // Move first half elements into firstHalf queue
        for (int i = 0; i < n / 2; i++) {
            firstHalf.add(q.poll());
        }
        
        // Interleave first half and second half
        while (!firstHalf.isEmpty()) {
            q.add(firstHalf.poll()); // element from first half
            q.add(q.poll());         // element from second half
        }
    }
}
