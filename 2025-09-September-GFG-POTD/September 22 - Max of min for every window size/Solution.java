class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];   // previous smaller
        int[] right = new int[n];  // next smaller
        Arrays.fill(left, -1);
        Arrays.fill(right, n);

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!dq.isEmpty() && arr[dq.peek()] >= arr[i]) {
                dq.pop();
            }
            if (!dq.isEmpty()) left[i] = dq.peek();
            dq.push(i);
        }

        dq.clear();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!dq.isEmpty() && arr[dq.peek()] >= arr[i]) {
                dq.pop();
            }
            if (!dq.isEmpty()) right[i] = dq.peek();
            dq.push(i);
        }

        int[] ans = new int[n + 1]; // max of min for window size
        // No need to fill with MIN_VALUE since arr[i] ≥ 1

        // Fill contributions
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = Math.max(ans[len], arr[i]);
        }

        // Propagate values
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }

        ArrayList<Integer> res = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            res.add(ans[i]);
        }

        return res;
    }
}
