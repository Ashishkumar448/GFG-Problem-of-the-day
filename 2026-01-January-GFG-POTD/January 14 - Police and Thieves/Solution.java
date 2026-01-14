class Solution {
    public int catchThieves(char[] arr, int k) {
        int n = arr.length;
        int i = 0, j = 0;
        
        // lists of indices
        java.util.List<Integer> police = new java.util.ArrayList<>();
        java.util.List<Integer> thieves = new java.util.ArrayList<>();
        
        for (int idx = 0; idx < n; idx++) {
            if (arr[idx] == 'P') police.add(idx);
            else thieves.add(idx);
        }
        
        int caught = 0;
        
        // two pointer approach
        while (i < police.size() && j < thieves.size()) {
            int p = police.get(i);
            int t = thieves.get(j);
            
            if (Math.abs(p - t) <= k) {
                caught++;
                i++;
                j++;
            }
            else if (t < p) j++;
            else i++;
        }
        
        return caught;
    }
}
