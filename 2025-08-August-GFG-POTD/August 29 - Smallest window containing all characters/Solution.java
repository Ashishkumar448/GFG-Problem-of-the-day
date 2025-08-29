class Solution {
    public static String smallestWindow(String s, String p) {
        if (s.length() < p.length()) return "";

        // frequency map for string p
        int[] freqP = new int[26];
        for (char c : p.toCharArray()) {
            freqP[c - 'a']++;
        }

        int[] freqS = new int[26];
        int count = 0; // number of chars matched
        int required = p.length();

        int minLen = Integer.MAX_VALUE;
        int minStart = 0;

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            freqS[c - 'a']++;

            // only count if char is needed
            if (freqP[c - 'a'] > 0 && freqS[c - 'a'] <= freqP[c - 'a']) {
                count++;
            }

            // When we have all required characters
            while (count == required) {
                // update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // try to shrink from left
                char leftChar = s.charAt(left);
                freqS[leftChar - 'a']--;

                if (freqP[leftChar - 'a'] > 0 && freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                    count--; // lose a required char
                }
                left++;
            }
        }

        return (minLen == Integer.MAX_VALUE) ? "" : s.substring(minStart, minStart + minLen);
    }
}
