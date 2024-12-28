#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findTriplets(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        res.push_back({i, j, k});
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution obj;
        vector<vector<int>> res = obj.findTriplets(nums);

        sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }
            return 0;
        });

        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (const auto& triplet : res) {
                for (int num : triplet) {
                    cout << num << " ";
                }
                cout << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}
