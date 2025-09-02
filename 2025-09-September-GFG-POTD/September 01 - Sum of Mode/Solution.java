class Solution {
    public int sumOfModes(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> freq = new HashMap<>();
        TreeMap<Integer, TreeSet<Integer>> groups = new TreeMap<>();
        
        // helper to add element
        Runnable add = new Runnable() {
            public void run() {} // dummy (Java lambdas below)
        };

        // add element
        java.util.function.Consumer<Integer> addElement = (x) -> {
            int oldCount = freq.getOrDefault(x, 0);
            int newCount = oldCount + 1;
            freq.put(x, newCount);
            
            // remove from old group
            if (oldCount > 0) {
                TreeSet<Integer> set = groups.get(oldCount);
                set.remove(x);
                if (set.isEmpty()) groups.remove(oldCount);
            }
            
            // add to new group
            groups.computeIfAbsent(newCount, z -> new TreeSet<>()).add(x);
        };
        
        // remove element
        java.util.function.Consumer<Integer> removeElement = (x) -> {
            int oldCount = freq.get(x);
            int newCount = oldCount - 1;
            
            // remove from old group
            TreeSet<Integer> set = groups.get(oldCount);
            set.remove(x);
            if (set.isEmpty()) groups.remove(oldCount);
            
            if (newCount == 0) {
                freq.remove(x);
            } else {
                freq.put(x, newCount);
                groups.computeIfAbsent(newCount, z -> new TreeSet<>()).add(x);
            }
        };
        
        int sum = 0;
        
        // build first window
        for (int i = 0; i < k; i++) {
            addElement.accept(arr[i]);
        }
        
        // process windows
        for (int i = k; i <= n; i++) {
            // get mode
            int maxFreq = groups.lastKey();
            int mode = groups.get(maxFreq).first(); // smallest element
            sum += mode;
            
            // slide window
            if (i < n) {
                removeElement.accept(arr[i - k]);
                addElement.accept(arr[i]);
            }
        }
        
        return sum;
    }
}
