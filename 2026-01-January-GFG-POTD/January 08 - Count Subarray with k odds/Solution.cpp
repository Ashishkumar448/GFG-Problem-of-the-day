class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }

private:
    int atMost(vector<int>& arr, int k) {
        int left = 0, count = 0, odds = 0;

        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] % 2 != 0) odds++;

            while (odds > k) {
                if (arr[left] % 2 != 0) odds--;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};
