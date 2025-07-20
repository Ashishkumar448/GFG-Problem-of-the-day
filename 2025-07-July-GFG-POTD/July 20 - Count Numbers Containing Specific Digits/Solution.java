class Solution {
    public int countValid(int n, int[] arr) {
        Set<Integer> includeSet = new HashSet<>();
        for (int d : arr) {
            includeSet.add(d);
        }

        // Step 1: Total n-digit numbers
        int total = 0;
        if (n == 1) {
            total = 9; // 1 to 9
        } else {
            total = 9 * (int)Math.pow(10, n - 1);
        }

        // Step 2: Complement digits
        List<Integer> complement = new ArrayList<>();
        for (int i = 0; i <= 9; i++) {
            if (!includeSet.contains(i)) {
                complement.add(i);
            }
        }

        // If no complement digits, all numbers are valid
        if (complement.size() == 0) return total;

        // Step 3: Count invalid numbers (using only complement digits)
        int invalid = 0;
        int len = complement.size();

        // First digit cannot be 0
        int firstDigitChoices = 0;
        for (int d : complement) {
            if (d != 0) firstDigitChoices++;
        }

        if (n == 1) {
            invalid = firstDigitChoices; // single-digit can't be 0
        } else {
            invalid = firstDigitChoices * (int)Math.pow(len, n - 1);
        }

        // Step 4: Valid = Total - Invalid
        return total - invalid;
    }
}
