#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int kthMissing(vector<int>& arr, int k) {
        int missingCount = 0; // Counts missing numbers
        int current = 1;      // Start from the smallest positive number
        int index = 0;        // Tracks position in the array

        while (true) {
            if (index < arr.size() && arr[index] == current) {
                // Current number is in the array, move to the next number
                index++;
            } else {
                // Current number is missing
                missingCount++;
                if (missingCount == k) {
                    return current; // Found the kth missing number
                }
            }
            current++;
        }
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

        int k;
        cin >> k;
        cin.ignore();

        Solution sol;
        int result = sol.kthMissing(arr, k);

        cout << result << endl;
        cout << "~" << endl;
    }

    return 0;
}

