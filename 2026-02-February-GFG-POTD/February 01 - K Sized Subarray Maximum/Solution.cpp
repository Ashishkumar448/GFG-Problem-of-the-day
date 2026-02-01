class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;  // stores indices

        for (int i = 0; i < arr.size(); i++) {

            // Remove indices out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Store max for the window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};
