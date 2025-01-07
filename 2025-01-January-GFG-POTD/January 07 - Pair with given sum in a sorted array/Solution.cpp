#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : arr) {
            res += freq[target - num];
            freq[num]++;
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t; // Input the number of test cases
    while (t--) {
        string inputLine;
        cin.ignore(); // To handle the newline after the number of test cases
        getline(cin, inputLine);

        vector<int> arr;
        stringstream ss(inputLine);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;

        Solution obj;
        int res = obj.countPairs(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
