class Solution {
   public void reverseQueue(Queue<Integer> q) {
        // base case: if queue is empty, return
        if (q.isEmpty()) {
            return;
        }

        // step 1: remove the front element
        int front = q.poll();

        // step 2: reverse the remaining queue
        reverseQueue(q);

        // step 3: add the removed element at the rear
        q.add(front);
    }

}
