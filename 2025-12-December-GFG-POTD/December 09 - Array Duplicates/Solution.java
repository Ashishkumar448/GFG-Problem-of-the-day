class Solution {
    public ArrayList<Integer> findDuplicates(int[] arr) {
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            int index = Math.abs(arr[i]) - 1;

            if (arr[index] < 0) {
                // Duplicate found
                result.add(index + 1);
            } else {
                // Mark as visited by making the value negative
                arr[index] = -arr[index];
            }
        }
        return result;
    }
}
