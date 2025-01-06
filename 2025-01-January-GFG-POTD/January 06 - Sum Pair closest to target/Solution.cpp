#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // Sort the array to enable two-pointer technique
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // Edge case: if less than two elements, return empty vector
        if (n < 2) return {};
        
        int closestSum = INT_MAX;
        int maxAbsDifference = INT_MIN;
        vector<int> result;

        int left = 0, right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            // Update closest sum and result pair if closer to target
            if (abs(sum - target) < abs(closestSum - target) || 
               (abs(sum - target) == abs(closestSum - target) &&
                abs(arr[right] - arr[left]) > maxAbsDifference)) {
                
                closestSum = sum;
                maxAbsDifference = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }

            // Move pointers based on sum comparison with target
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.sumClosest(arr, target);

        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (int num : res) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
