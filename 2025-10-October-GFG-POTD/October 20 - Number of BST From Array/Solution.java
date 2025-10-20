class Solution {
    private Map<Integer, Integer> memo = new HashMap<>();

    private int numBST(int n) {
        if (n <= 1) return 1;
        if (memo.containsKey(n)) return memo.get(n);

        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += numBST(i - 1) * numBST(n - i);
        }
        memo.put(n, total);
        return total;
    }

    public ArrayList<Integer> countBSTs(int[] arr) {
        ArrayList<Integer> result = new ArrayList<>();
        int n = arr.length;

        // Make a sorted copy to find left/right counts easily
        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        // Map each value to its count of BSTs
        Map<Integer, Integer> bstMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int leftCount = i;             // elements smaller than sorted[i]
            int rightCount = n - i - 1;    // elements greater than sorted[i]
            int count = numBST(leftCount) * numBST(rightCount);
            bstMap.put(sorted[i], count);
        }

        // Now build result in the same order as input array
        for (int val : arr) {
            result.add(bstMap.get(val));
        }

        return result;
    }
}
