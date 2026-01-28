class Solution {
     public int countSubset(int[] arr, int k) {
        int n = arr.length;
        int mid = n / 2;

        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, n);

        Map<Integer, Integer> leftSumCount = new HashMap<>();
        generateSums(left, 0, 0, leftSumCount);

        int[] count = new int[1];
        generateAndCount(right, 0, 0, k, leftSumCount, count);

        return count[0];
    }

    // Generate all subset sums of left half
    private void generateSums(int[] arr, int index, int sum,
                              Map<Integer, Integer> map) {
        if (index == arr.length) {
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            return;
        }
        generateSums(arr, index + 1, sum, map);
        generateSums(arr, index + 1, sum + arr[index], map);
    }

    // Generate sums of right half and count valid pairs
    private void generateAndCount(int[] arr, int index, int sum, int k,
                                  Map<Integer, Integer> map, int[] count) {
        if (index == arr.length) {
            count[0] += map.getOrDefault(k - sum, 0);
            return;
        }
        generateAndCount(arr, index + 1, sum, k, map, count);
        generateAndCount(arr, index + 1, sum + arr[index], k, map, count);
    }
}
