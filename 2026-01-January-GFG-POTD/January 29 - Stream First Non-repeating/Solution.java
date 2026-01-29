class Solution {
    public String firstNonRepeating(String s) {
        int[] freq = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder result = new StringBuilder();

        for (char ch : s.toCharArray()) {
            // Update frequency
            freq[ch - 'a']++;

            // Add current character to queue
            q.offer(ch);

            // Remove repeating characters from front
            while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
                q.poll();
            }

            // Append result for current prefix
            if (q.isEmpty()) {
                result.append('#');
            } else {
                result.append(q.peek());
            }
        }

        return result.toString();
    }
}
