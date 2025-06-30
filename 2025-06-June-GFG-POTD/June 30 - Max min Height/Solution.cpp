class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> water(n + 1, 0);
        long long opsUsed = 0;
        long long curWater = 0;

        for (int i = 0; i < n; i++) {
            curWater += water[i];
            int currentHeight = arr[i] + curWater;
            if (currentHeight < target) {
                int delta = target - currentHeight;
                opsUsed += delta;
                if (opsUsed > k) return false;

                curWater += delta;
                if (i + w < n)
                    water[i + w] -= delta;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int answer = low;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};
