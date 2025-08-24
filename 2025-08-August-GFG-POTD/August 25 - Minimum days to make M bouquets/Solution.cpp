class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        
        // If not enough flowers
        if ((long long)m * k > n) return -1;
        
        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());
        
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                right = mid - 1; // try smaller
            } else {
                left = mid + 1; // need more days
            }
        }
        return ans;
    }
    
private:
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int count = 0, bouquets = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0; // reset streak
            }
            if (bouquets >= m) return true;
        }
        return false;
    }
};
