class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        long long expectedSum = (1LL * n * (n + 1)) / 2;

        long long actualSum = 0;
        for (int num : arr) {
            actualSum += num;
        }

        return static_cast<int>(expectedSum - actualSum);
    }
};
