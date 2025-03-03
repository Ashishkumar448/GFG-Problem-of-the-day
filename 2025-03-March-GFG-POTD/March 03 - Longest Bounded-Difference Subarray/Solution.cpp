#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0, startIdx = 0;
        map<int, int> window; // Ordered map to track element frequencies

        while (right < n) {
            window[arr[right]]++;

            // Shrink window if max - min > x
            while (!window.empty() && window.rbegin()->first - window.begin()->first > x) {
                if (--window[arr[left]] == 0)
                    window.erase(arr[left]);
                left++;
            }

            // Update max subarray length
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }

            right++;
        }

        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        cin >> x;

        Solution obj;
        vector<int> ans = obj.longestSubarray(arr, x);

        for (int num : ans) cout << num << " ";
        cout << endl;
    }
    return 0;
}
