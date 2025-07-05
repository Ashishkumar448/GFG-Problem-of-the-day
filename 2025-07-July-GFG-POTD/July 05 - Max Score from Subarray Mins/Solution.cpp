class Solution {
public:
    int maxSum(vector<int>& arr) {
        int maxScore = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int sum = arr[i] + arr[i + 1];
            if (sum > maxScore) {
                maxScore = sum;
            }
        }
        return maxScore;
    }
};
