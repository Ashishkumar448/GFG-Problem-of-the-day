class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0;  // Pointer for next non-zero position
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
                j++;
            }
        }
    }
};
