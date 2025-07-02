class Solution {
    public int totalElements(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxLen = 0, start = 0;

        for (int end = 0; end < arr.length; end++) {
            map.put(arr[end], map.getOrDefault(arr[end], 0) + 1);

            // Shrink the window if we have more than 2 distinct integers
            while (map.size() > 2) {
                map.put(arr[start], map.get(arr[start]) - 1);
                if (map.get(arr[start]) == 0) {
                    map.remove(arr[start]);
                }
                start++;
            }

            // Update max length
            maxLen = Math.max(maxLen, end - start + 1);
        }

        return maxLen;
    }
}
