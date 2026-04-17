class Solution {
    boolean canFormPalindrome(String s) {
        int[] freq = new int[26];
        
        // Count frequency of each character
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        
        // Count characters with odd frequency
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        
        // At most one odd frequency allowed
        return oddCount <= 1;
    }
}
