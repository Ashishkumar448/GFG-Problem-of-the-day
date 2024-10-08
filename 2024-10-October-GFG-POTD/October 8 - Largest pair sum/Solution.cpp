#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pairsum(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Return the sum of the two largest elements
        return arr[arr.size() - 1] + arr[arr.size() - 2];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle the newline after the number of test cases
    while (t--) {
        string line;
        getline(cin, line);

        // Parse the line into a vector of integers
        vector<int> array;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            array.push_back(number);
        }

        Solution obj;
        int res = obj.pairsum(array);

        cout << res << endl;
    }
    return 0;
}
