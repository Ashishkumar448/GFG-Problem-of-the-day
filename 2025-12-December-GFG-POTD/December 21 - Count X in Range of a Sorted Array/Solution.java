class Solution {
    public ArrayList<Integer> countXInRange(int[] arr, int[][] queries) {
        ArrayList<Integer> result = new ArrayList<>();

        // Step 1: Preprocess positions
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }

        // Step 2: Answer queries
        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            if (!map.containsKey(x)) {
                result.add(0);
                continue;
            }

            ArrayList<Integer> indices = map.get(x);

            int left = lowerBound(indices, l);
            int right = upperBound(indices, r);

            result.add(right - left);
        }

        return result;
    }

    // First index >= target
    private int lowerBound(ArrayList<Integer> list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    // First index > target
    private int upperBound(ArrayList<Integer> list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
}
