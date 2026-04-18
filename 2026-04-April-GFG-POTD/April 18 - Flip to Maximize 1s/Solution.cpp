class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;
        
        // Count total 1s
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }
        
        int maxGain = 0;
        int currGain = 0;
        
        for (int x : arr) {
            // Transform: 0 -> +1, 1 -> -1
            int val = (x == 0) ? 1 : -1;
            
            currGain = max(val, currGain + val);
            maxGain = max(maxGain, currGain);
        }
        
        return totalOnes + maxGain;
    }
};
