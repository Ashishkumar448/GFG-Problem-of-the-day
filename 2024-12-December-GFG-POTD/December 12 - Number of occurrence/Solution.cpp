#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        // Find the first occurrence of the target
        int first = findFirstOccurrence(arr, target);
        if (first == -1) {
            // Target not found in the array
            return 0;
        }

        // Find the last occurrence of the target
        int last = findLastOccurrence(arr, target);

        // The number of occurrences is (last - first + 1)
        return last - first + 1;
    }

private:
    int findFirstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                high = mid - 1; // Narrow search to the left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    int findLastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                low = mid + 1; // Narrow search to the right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    int tc;
    cin >> tc;

    while (tc-- > 0) {
        vector<int> arr;
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;

        Solution sln;
        cout << sln.countFreq(arr, target) << endl;
        cout << "~" << endl;
    }

    return 0;
}
