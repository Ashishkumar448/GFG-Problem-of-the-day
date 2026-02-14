class Solution {
public:
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long currentTime = 0;

        for (int length : arr) {
            if (currentTime + length <= maxTime) {
                currentTime += length;
            } else {
                painters++;
                currentTime = length;

                if (painters > k) {
                    return false;
                }
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = 0, high = 0;

        for (int length : arr) {
            low = max(low, (long long)length);
            high += length;
        }

        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)result;
    }
};
