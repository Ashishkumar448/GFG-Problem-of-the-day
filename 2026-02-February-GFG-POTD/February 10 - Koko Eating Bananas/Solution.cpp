class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = 0;

        // Find max pile
        for (int bananas : arr) {
            high = max(high, bananas);
        }

        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(arr, k, mid)) {
                answer = mid;        // try smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;       // need higher speed
            }
        }

        return answer;
    }

private:
    bool canFinish(vector<int>& arr, int k, int speed) {
        long long hours = 0;

        for (int bananas : arr) {
            hours += (bananas + speed - 1) / speed; // ceil division
            if (hours > k) return false;
        }

        return true;
    }
};
