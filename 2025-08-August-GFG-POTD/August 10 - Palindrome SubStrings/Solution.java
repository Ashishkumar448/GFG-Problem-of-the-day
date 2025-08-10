class Solution {
    public int countPS(String s) {
        int n = s.length();
        int count = 0;

        // Expand around center for odd-length palindromes
        for (int center = 0; center < n; center++) {
            count += expandFromCenter(s, center, center);     // odd
            count += expandFromCenter(s, center, center + 1); // even
        }

        return count;
    }

    private int expandFromCenter(String s, int left, int right) {
        int cnt = 0;
        int n = s.length();
        while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
            if (right - left + 1 >= 2) { // only count if length ≥ 2
                cnt++;
            }
            left--;
            right++;
        }
        return cnt;
    }
}
