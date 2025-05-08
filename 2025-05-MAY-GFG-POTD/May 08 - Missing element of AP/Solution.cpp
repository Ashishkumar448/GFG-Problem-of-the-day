class Solution {
public:
    int findMissing(std::vector<int>& arr) {
        int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] != d) {
                return arr[i] + d;
            }
        }

        // If no missing element, return the next element in AP
        return arr[n - 1] + d;
    }
};
