#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        if (n == 2) return max(arr[0], arr[1]);

        return max(rob(vector<int>(arr.begin(), arr.end() - 1)), 
                   rob(vector<int>(arr.begin() + 1, arr.end())));
    }

private:
    int rob(vector<int> arr) {
        int prev2 = 0, prev1 = 0;
        for (int num : arr) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        Solution obj;
        int res = obj.maxValue(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
