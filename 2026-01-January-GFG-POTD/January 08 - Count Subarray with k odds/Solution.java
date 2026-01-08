class Solution {
    public int countSubarrays(int[] arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
    
    private int atMost(int[] arr, int k) {
        int left = 0, count = 0;
        int odds = 0;
        
        for(int right = 0; right < arr.length; right++){
            if(arr[right] % 2 != 0) odds++;
            
            while(odds > k){
                if(arr[left] % 2 != 0) odds--;
                left++;
            }
            
            // all subarrays ending at right with valid window
            count += (right - left + 1);
        }
        
        return count;
    }
}
