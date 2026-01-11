class Solution {
    public String minWindow(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int minLen = Integer.MAX_VALUE;
        int startIndex = -1;

        int i = 0;
        while (i < n) {
            int j = 0;

            // Move forward to match s2 as subsequence
            while (i < n) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            // If we reached end without full match
            if (i == n) break;

            // Now shrink window backwards
            int end = i;
            j = m - 1;

            while (i >= 0) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            // i is now at start of valid window
            int start = i;
            int windowLen = end - start + 1;

            if (windowLen < minLen) {
                minLen = windowLen;
                startIndex = start;
            }

            // Move to next possible starting point
            i = start + 1;
        }

        return startIndex == -1 ? "" : s1.substring(startIndex, startIndex + minLen);
    }
}
