class SpecialQueue {

    private Queue<Integer> q;
    private Deque<Integer> minDeque;
    private Deque<Integer> maxDeque;

    public SpecialQueue() {
        q = new LinkedList<>();
        minDeque = new ArrayDeque<>();
        maxDeque = new ArrayDeque<>();
    }

    public void enqueue(int x) {
        q.offer(x);

        // Maintain minDeque in increasing order
        while (!minDeque.isEmpty() && minDeque.peekLast() > x) {
            minDeque.pollLast();
        }
        minDeque.offerLast(x);

        // Maintain maxDeque in decreasing order
        while (!maxDeque.isEmpty() && maxDeque.peekLast() < x) {
            maxDeque.pollLast();
        }
        maxDeque.offerLast(x);
    }

    public void dequeue() {
        if (!q.isEmpty()) {
            int val = q.poll();
            if (!minDeque.isEmpty() && minDeque.peekFirst() == val) {
                minDeque.pollFirst();
            }
            if (!maxDeque.isEmpty() && maxDeque.peekFirst() == val) {
                maxDeque.pollFirst();
            }
        }
    }

    public int getFront() {
        return q.peek();
    }

    public int getMin() {
        return minDeque.peekFirst();
    }

    public int getMax() {
        return maxDeque.peekFirst();
    }
}
