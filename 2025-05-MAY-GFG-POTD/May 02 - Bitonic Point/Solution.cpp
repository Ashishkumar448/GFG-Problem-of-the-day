#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximum(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid > 0 && mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                    return arr[mid];
                else if (arr[mid] > arr[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else if (mid == 0) {
                return max(arr[0], arr[1]);
            } else if (mid == arr.size() - 1) {
                return max(arr[arr.size() - 1], arr[arr.size() - 2]);
            }
        }
        return -1;
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
        int num;
        vector<int> arr;

        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        cout << sol.findMaximum(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
