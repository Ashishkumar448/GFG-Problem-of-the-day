#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
public:
    int getSecondLargest(const vector<int>& arr) {
        if (arr.size() < 2) {
            return -1; // Return -1 if there are not enough elements for a second largest
        }
        
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;  // update second largest before updating largest
                largest = num;
            } else if (num > secondLargest && num < largest) {
                secondLargest = num;  // update second largest if num is less than largest but greater than secondLargest
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<int> arr;
        int num;

        while (iss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
