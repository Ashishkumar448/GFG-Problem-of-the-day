class Solution {
    public int minValue(String s, int k) {
        // Frequency array for 26 lowercase characters
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Max heap to store frequencies
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int f : freq) {
            if (f > 0) {
                maxHeap.add(f);
            }
        }

        // Remove k characters
        while (k > 0 && !maxHeap.isEmpty()) {
            int top = maxHeap.poll();
            top--; // Remove one character
            k--;
            if (top > 0) {
                maxHeap.add(top);
            }
        }

        // Calculate the sum of squares of remaining frequencies
        int result = 0;
        while (!maxHeap.isEmpty()) {
            int remaining = maxHeap.poll();
            result += remaining * remaining;
        }

        return result;
    }
}
