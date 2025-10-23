class Solution {
    public void nearlySorted(int[] arr, int k) {
        // Create a min heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        int n = arr.length;
        int index = 0; // to place sorted elements back in arr
        
        // Step 1: Add first k+1 elements to heap
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.add(arr[i]);
        }
        
        // Step 2: Process the remaining elements
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.poll(); // place smallest in correct position
            minHeap.add(arr[i]);           // push new element into heap
        }
        
        // Step 3: Extract remaining elements from heap
        while (!minHeap.isEmpty()) {
            arr[index++] = minHeap.poll();
        }
    }
}
