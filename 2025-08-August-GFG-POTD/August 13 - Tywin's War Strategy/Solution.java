class Solution {
     public int minSoldiers(int[] arr, int k) {
        int n = arr.length;
        int required = (n + 1) / 2; // ceil(n / 2)
        int luckyCount = 0;
        List<Integer> addList = new ArrayList<>();
        
        for (int num : arr) {
            if (num % k == 0) {
                luckyCount++;
            } else {
                addList.add(k - (num % k));
            }
        }
        
        // If already enough lucky troops
        if (luckyCount >= required) {
            return 0;
        }
        
        // Sort costs to make troops lucky
        Collections.sort(addList);
        
        int soldiersNeeded = 0;
        int toMakeLucky = required - luckyCount;
        
        for (int i = 0; i < toMakeLucky; i++) {
            soldiersNeeded += addList.get(i);
        }
        
        return soldiersNeeded;
    }
}
