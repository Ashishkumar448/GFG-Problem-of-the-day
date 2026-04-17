class Solution {
public:
    bool canFormPalindrome(string s) {
        vector<int> freq(26, 0);
        
        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        
        // Count odd frequencies
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        
        return oddCount <= 1;
    }
};
