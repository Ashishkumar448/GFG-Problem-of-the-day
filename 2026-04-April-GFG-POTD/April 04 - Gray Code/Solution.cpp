class Solution {
public:
    vector<string> graycode(int n) {
        vector<string> result;
        
        // Base case
        result.push_back("0");
        if (n == 1) {
            result.push_back("1");
            return result;
        }
        
        result.push_back("1");
        
        // Build from 2 to n
        for (int i = 2; i <= n; i++) {
            int size = result.size();
            
            // Step 1: Add reversed elements
            for (int j = size - 1; j >= 0; j--) {
                result.push_back(result[j]);
            }
            
            // Step 2: Add '0' prefix to first half
            for (int j = 0; j < size; j++) {
                result[j] = "0" + result[j];
            }
            
            // Step 3: Add '1' prefix to second half
            for (int j = size; j < result.size(); j++) {
                result[j] = "1" + result[j];
            }
        }
        
        return result;
    }
};
