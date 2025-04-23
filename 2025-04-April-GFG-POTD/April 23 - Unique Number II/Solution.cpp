#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;

        // Step 1: XOR all elements
        for (int num : arr) {
            xor_all ^= num;
        }

        // Step 2: Find rightmost set bit
        int setBit = xor_all & -xor_all;

        int num1 = 0, num2 = 0;

        // Step 3: Divide into two groups and XOR separately
        for (int num : arr) {
            if (num & setBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        // Step 4: Return in increasing order
        vector<int> result = {num1, num2};
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To skip the newline after reading t

    while (t--) {
        string line;
        getline(cin, line);

        vector<int> arr;
        int num;
        stringstream ss(line);
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sol;
        vector<int> result = sol.singleNum(arr);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl << "~" << endl;
    }

    return 0;
}
