#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTarget(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to skip the newline after number of test cases

    while (t--) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num = 0;
        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                arr.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (line[i] - '0');
            }
        }
        arr.push_back(num); // push last number

        int target;
        cin >> target;
        cin.ignore(); // skip newline

        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
