class Solution {
    public ArrayList<Integer> asciirange(String s) {
        ArrayList<Integer> result = new ArrayList<>();
        HashSet<Character> seen = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            // Skip if already processed
            if (seen.contains(ch)) continue;

            int first = s.indexOf(ch);
            int last = s.lastIndexOf(ch);

            if (first != last) {
                int sum = 0;
                for (int j = first + 1; j < last; j++) {
                    sum += (int) s.charAt(j);
                }

                if (sum > 0) {
                    result.add(sum);
                }
            }

            seen.add(ch);
        }

        return result;
    }
}
