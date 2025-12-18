class Solution {
     public void sortIt(int[] arr) {
        List<Integer> odd = new ArrayList<>();
        List<Integer> even = new ArrayList<>();

        // Separate odd and even numbers
        for (int num : arr) {
            if (num % 2 != 0) {
                odd.add(num);
            } else {
                even.add(num);
            }
        }

        // Sort odd in descending order
        Collections.sort(odd, Collections.reverseOrder());

        // Sort even in ascending order
        Collections.sort(even);

        // Merge back into original array
        int index = 0;
        for (int num : odd) {
            arr[index++] = num;
        }
        for (int num : even) {
            arr[index++] = num;
        }
    }
}
