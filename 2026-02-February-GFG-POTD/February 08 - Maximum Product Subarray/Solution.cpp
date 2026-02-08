class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int globalMax = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int curr = arr[i];

            // If current element is negative, swap max and min
            if (curr < 0) {
                swap(maxEndingHere, minEndingHere);
            }

            maxEndingHere = max(curr, maxEndingHere * curr);
            minEndingHere = min(curr, minEndingHere * curr);

            globalMax = max(globalMax, maxEndingHere);
        }

        return globalMax;
    }
};
