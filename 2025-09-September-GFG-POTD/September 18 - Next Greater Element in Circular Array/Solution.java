class Solution {
    public ArrayList<Integer> nextGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> st = new Stack<>();

        // Traverse the array twice (simulate circular behavior)
        for (int i = 0; i < 2 * n; i++) {
            int num = arr[i % n];

            // While stack is not empty and current number is greater
            while (!st.isEmpty() && arr[st.peek()] < num) {
                int idx = st.pop();
                res.set(idx, num);
            }

            // Only push index in first round
            if (i < n) {
                st.push(i);
            }
        }

        return res;
    }
}
