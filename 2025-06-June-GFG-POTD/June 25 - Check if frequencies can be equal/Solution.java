class Solution {
    boolean sameFreq(String s) {
        Map<Character, Integer> freqMap = new HashMap<>();
        
        // Step 1: Count frequencies of characters
        for (char ch : s.toCharArray()) {
            freqMap.put(ch, freqMap.getOrDefault(ch, 0) + 1);
        }

        // Step 2: Count frequencies of frequencies
        Map<Integer, Integer> freqCount = new HashMap<>();
        for (int freq : freqMap.values()) {
            freqCount.put(freq, freqCount.getOrDefault(freq, 0) + 1);
        }

        // Case 1: All frequencies same
        if (freqCount.size() == 1) return true;

        // Case 2: Only two different frequencies
        if (freqCount.size() == 2) {
            List<Integer> keys = new ArrayList<>(freqCount.keySet());
            int f1 = keys.get(0), f2 = keys.get(1);
            int c1 = freqCount.get(f1), c2 = freqCount.get(f2);

            // Case A: one frequency is 1 and occurs once: {1:1, x:n}
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;

            // Case B: difference between frequencies is 1 and the higher one occurs only once
            if ((Math.abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) {
                return true;
            }
        }

        // Otherwise, not possible
        return false;
    }
}
