class Solution {
    public ArrayList<Integer> topKFreq(int[] arr, int k) {
        // Step 1: Count frequency of each element
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Use a PriorityQueue (Max-Heap) with custom comparator
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
            (a, b) -> {
                if (b.getValue().equals(a.getValue())) {
                    return b.getKey() - a.getKey(); // higher number first if freq same
                } else {
                    return b.getValue() - a.getValue(); // higher freq first
                }
            }
        );

        // Step 3: Add all entries to PQ
        pq.addAll(freqMap.entrySet());

        // Step 4: Extract top k elements
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < k && !pq.isEmpty(); i++) {
            result.add(pq.poll().getKey());
        }

        return result;
    }
}
