class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Build freq for first window
        for(int i = 0; i < k; i++){
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        ans.add(map.size());
        
        // Slide the window
        for(int i = k; i < arr.length; i++){
            int outgoing = arr[i - k];
            // decrease outgoing
            map.put(outgoing, map.get(outgoing) - 1);
            if(map.get(outgoing) == 0) map.remove(outgoing);
            
            // add new incoming
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
            
            ans.add(map.size());
        }
        
        return ans;
    }
}
