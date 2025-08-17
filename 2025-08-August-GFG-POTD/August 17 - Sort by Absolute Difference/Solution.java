class Solution {
    public void rearrange(int[] arr, int x) {
        // Convert primitive array to List of Integers for sorting with comparator
        List<Integer> list = new ArrayList<>();
        for (int num : arr) {
            list.add(num);
        }

        // Sort using a stable comparator
        Collections.sort(list, (a, b) -> {
            int diff1 = Math.abs(a - x);
            int diff2 = Math.abs(b - x);
            return diff1 - diff2; // smaller difference comes first
        });

        // Copy back to original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i);
        }
    }
}
