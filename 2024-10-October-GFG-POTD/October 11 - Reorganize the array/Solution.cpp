#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrange(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            int value = arr[i];
            if (value >= 0 && value < n) {
                result[value] = value;
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline character

    Solution solution;

    while (t-- > 0) {
        string input;
        getline(cin, input);
        vector<int> arr;
        int num;
        size_t pos = 0;

        // Splitting the string input into integers
        while ((pos = input.find(" ")) != string::npos) {
            num = stoi(input.substr(0, pos));
            arr.push_back(num);
            input.erase(0, pos + 1);
        }
        // Add the last element
        arr.push_back(stoi(input));

        vector<int> ans = solution.rearrange(arr);

        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
