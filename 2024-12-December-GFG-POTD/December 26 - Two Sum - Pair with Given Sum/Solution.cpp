#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];

            if (map.find(complement) != map.end()) {
                return true;
            }

            map[arr[i]] = i;
        }

        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;

        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        bool ans = obj.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }
    return 0;
}
