// User function Template for Java

class Solution {
    int countSubstr(String s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }

    private int countAtMostK(String s, int k) {
        int left = 0, right = 0, res = 0;
        Map<Character, Integer> freqMap = new HashMap<>();

        for (right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);

            // Shrink the window until we have at most k distinct characters
            while (freqMap.size() > k) {
                char leftChar = s.charAt(left);
                freqMap.put(leftChar, freqMap.get(leftChar) - 1);
                if (freqMap.get(leftChar) == 0) {
                    freqMap.remove(leftChar);
                }
                left++;
            }

            // All substrings ending at 'right' and starting from 'left' to 'right' are valid
            res += right - left + 1;
        }

        return res;
    }
}
