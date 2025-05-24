class Solution {
    public static int sumSubstrings(String s) {
        int n = s.length();
        long res = 0;
        long prev = 0;

        for (int i = 0; i < n; i++) {
            int num = s.charAt(i) - '0';
            prev = prev * 10 + (long) num * (i + 1);
            res += prev;
        }

        return (int) res;
    }
}
