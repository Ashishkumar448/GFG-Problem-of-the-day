class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Precompute Catalan numbers
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        if (n >= 1) catalan[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        
        vector<int> result;
        
        // Step 2: Compute answer for each root
        for (int i = 0; i < n; i++) {
            int root = arr[i];
            int leftCount = 0, rightCount = 0;
            
            for (int j = 0; j < n; j++) {
                if (arr[j] < root) leftCount++;
                else if (arr[j] > root) rightCount++;
            }
            
            result.push_back(catalan[leftCount] * catalan[rightCount]);
        }
        
        return result;
    }
};
