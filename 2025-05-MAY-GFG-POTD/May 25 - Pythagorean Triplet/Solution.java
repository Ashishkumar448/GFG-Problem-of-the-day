class Solution {
   boolean pythagoreanTriplet(int[] arr) {
        int n = arr.length;

        // Square all elements
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }

        // Try every pair (a, b) and check if (a^2 + b^2) exists in the array
        HashSet<Integer> squares = new HashSet<>();
        for (int num : arr) {
            squares.add(num);
        }

        // Loop through all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                if (squares.contains(sum)) {
                    return true;
                }
            }
        }

        return false;
    }
}
