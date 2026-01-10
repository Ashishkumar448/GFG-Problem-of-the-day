class Solution {
        public int countSubstr(String s, int k) {
        if(k == 0) return 0;
        return (int)(atMostK(s, k) - atMostK(s, k - 1));
    }
    
    private long atMostK(String s, int k){
        int n = s.length();
        int[] freq = new int[26];
        int left = 0;
        long count = 0;
        int distinct = 0;
        
        for(int right = 0; right < n; right++){
            int r = s.charAt(right) - 'a';
            if(freq[r] == 0) distinct++;
            freq[r]++;
            
            while(distinct > k){
                int l = s.charAt(left) - 'a';
                freq[l]--;
                if(freq[l] == 0) distinct--;
                left++;
            }
            
            // Number of substrings ending at right
            count += right - left + 1;
        }
        
        return count;
    }

}
