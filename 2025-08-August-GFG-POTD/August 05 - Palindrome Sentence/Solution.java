class Solution {
    public boolean isPalinSent(String s) {
        // Step 1: Normalize the string
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                sb.append(Character.toLowerCase(c));
            }
        }
        
        // Step 2: Check if the cleaned string is a palindrome
        int left = 0;
        int right = sb.length() - 1;
        
        while (left < right) {
            if (sb.charAt(left) != sb.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
}
