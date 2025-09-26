class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;  // edge case
        k = k % n;  // optimize to avoid extra rotations

        if (type == 1) {  // Right rotation
            for (int i = 0; i < k; i++) {
                int val = dq.removeLast();
                dq.addFirst(val);
            }
        } else if (type == 2) {  // Left rotation
            for (int i = 0; i < k; i++) {
                int val = dq.removeFirst();
                dq.addLast(val);
            }
        }
    }

    // quick test
    public static void main(String[] args) {
        Deque<Integer> dq1 = new LinkedList<>(Arrays.asList(1, 2, 3, 4, 5, 6));
        rotateDeque(dq1, 1, 2);
        System.out.println(dq1); // [5, 6, 1, 2, 3, 4]

        Deque<Integer> dq2 = new LinkedList<>(Arrays.asList(10, 20, 30, 40, 50));
        rotateDeque(dq2, 2, 3);
        System.out.println(dq2); // [40, 50, 10, 20, 30]
    }
}
