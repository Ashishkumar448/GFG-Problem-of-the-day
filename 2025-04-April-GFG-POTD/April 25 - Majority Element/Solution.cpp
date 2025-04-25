#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate = -1;

        // Step 1: Find a candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify the candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        return count > arr.size() / 2 ? candidate : -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        stringstream ss(line);
        while (ss >> num) arr.push_back(num);
        Solution sol;
        cout << sol.majorityElement(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
