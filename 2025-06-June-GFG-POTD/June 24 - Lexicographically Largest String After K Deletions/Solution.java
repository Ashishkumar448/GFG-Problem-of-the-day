class Solution {
    public static String maxSubseq(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            while (k > 0 && sb.length() > 0 && sb.charAt(sb.length() - 1) < c) {
                sb.deleteCharAt(sb.length() - 1);
                k--;
            }
            sb.append(c);
        }
        if (k > 0) {
            sb.setLength(sb.length() - k);
        }
        return sb.toString();
    }
}
