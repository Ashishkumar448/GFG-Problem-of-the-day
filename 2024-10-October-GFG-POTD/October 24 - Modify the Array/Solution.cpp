#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> modifyAndRearrangeArr(vector<int>& arr) {
        // Step 1: Modify the array by merging adjacent duplicate elements
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1] && arr[i] != 0) {
                arr[i] = arr[i] * 2;  // Merge duplicates
                arr[i + 1] = 0;       // Set next element to 0
            }
        }

        // Step 2: Rearrange the array by moving all zeroes to the end
        vector<int> result;
        int zeroCount = 0;

        // Add non-zero elements to the result vector
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                result.push_back(arr[i]);
            } else {
                zeroCount++;
            }
        }

        // Append the zeroes at the end of the result vector
        while (zeroCount-- > 0) {
            result.push_back(0);
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int num;
        string line;
        cin.ignore(); // Ignore leftover newline
        getline(cin, line); // Input line of numbers
        istringstream iss(line);
        while (iss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        vector<int> result = sol.modifyAndRearrangeArr(arr);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
