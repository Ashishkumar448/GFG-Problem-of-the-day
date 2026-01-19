class Solution {
    public String removeKdig(String s, int k) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            // Remove larger digits from stack if possible
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }

        // If k digits still need to be removed, remove from end
        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }

        // Build result string
        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < sb.length() && sb.charAt(idx) == '0') {
            idx++;
        }

        String result = sb.substring(idx);

        // If empty, return "0"
        return result.isEmpty() ? "0" : result;
    }
}
