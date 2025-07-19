class Solution {
    public int vowelCount(String s) {
        Map<Character, Integer> vowelCounts = new HashMap<>();
        Set<Character> vowelsSet = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));

        // Count occurrences of each vowel
        for (char ch : s.toCharArray()) {
            if (vowelsSet.contains(ch)) {
                vowelCounts.put(ch, vowelCounts.getOrDefault(ch, 0) + 1);
            }
        }

        // If no vowels, return 0
        if (vowelCounts.isEmpty()) return 0;

        // Product of choices (each occurrence is a choice)
        int choices = 1;
        for (int count : vowelCounts.values()) {
            choices *= count;
        }

        // Factorial of number of unique vowels (number of permutations)
        int perm = factorial(vowelCounts.size());

        return choices * perm;
    }

    private int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
}
