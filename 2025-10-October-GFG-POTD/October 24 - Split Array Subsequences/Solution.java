class Solution {

    public boolean isPossible(int[] arr, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        Map<Integer, Integer> endAt = new HashMap<>();

        // Step 1: Count frequency of each number
        for (int num : arr) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        // Step 2: Traverse and form subsequences
        for (int num : arr) {
            if (count.get(num) == 0) continue;

            // Case 1: Extend an existing subsequence ending at num - 1
            if (endAt.getOrDefault(num - 1, 0) > 0) {
                endAt.put(num - 1, endAt.get(num - 1) - 1);
                endAt.put(num, endAt.getOrDefault(num, 0) + 1);
                count.put(num, count.get(num) - 1);
            }
            // Case 2: Start a new subsequence of length k
            else {
                boolean possible = true;
                for (int i = 0; i < k; i++) {
                    if (count.getOrDefault(num + i, 0) <= 0) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) return false;

                for (int i = 0; i < k; i++) {
                    count.put(num + i, count.get(num + i) - 1);
                }
                endAt.put(num + k - 1, endAt.getOrDefault(num + k - 1, 0) + 1);
            }
        }

        return true;
    }
}
