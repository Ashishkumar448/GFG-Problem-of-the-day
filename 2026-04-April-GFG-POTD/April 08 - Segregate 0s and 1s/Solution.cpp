class Solution {
public:
    void segregate0and1(vector<int>& arr) {
        int countZero = 0;

        // Count zeros
        for (int num : arr) {
            if (num == 0) countZero++;
        }

        // Fill array
        for (int i = 0; i < arr.size(); i++) {
            if (i < countZero) arr[i] = 0;
            else arr[i] = 1;
        }
    }
};
