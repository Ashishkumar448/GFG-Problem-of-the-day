class Solution {
    public int longestKSubstr(String s, int k) {
        int n = s.length();
        if (n == 0 || k == 0) return -1;

        Map<Character, Integer> map = new HashMap<>();
        int maxLength = -1;
        int start = 0;

        for (int end = 0; end < n; end++) {
            char ch = s.charAt(end);
            map.put(ch, map.getOrDefault(ch, 0) + 1);

            while (map.size() > k) {
                char leftChar = s.charAt(start);
                map.put(leftChar, map.get(leftChar) - 1);
                if (map.get(leftChar) == 0) {
                    map.remove(leftChar);
                }
                start++;
            }

            if (map.size() == k) {
                maxLength = Math.max(maxLength, end - start + 1);
            }
        }

        return maxLength;
    }
}
