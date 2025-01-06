#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        // Sort the array
        sort(arr.begin(), arr.end());
        int count = 0;
        int left = 0, right = arr.size() - 1;

        // Use two pointers
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum < target) {
                // If the sum is less than the target,
                // all pairs (arr[left], arr[left + 1], ..., arr[right]) are valid
                count += (right - left);
                left++;
            } else {
                right--; // Decrease right to reduce the sum
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore();
        getline(cin, line);

        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        int target;
        cin >> target;

        Solution obj;
        cout << obj.countPairs(nums, target) << endl;
        cout << "~" << endl;
    }
    return 0;
}
