#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(vector<int>& arr) {
        vector<int> pos; // To store positive numbers
        vector<int> neg; // To store negative numbers

        // Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        // Merging them back into arr alternately
        int i = 0, p = 0, n = 0;
        bool turnPositive = true;

        // Alternate between positive and negative numbers
        while (p < pos.size() && n < neg.size()) {
            if (turnPositive) {
                arr[i++] = pos[p++];
            } else {
                arr[i++] = neg[n++];
            }
            turnPositive = !turnPositive;
        }

        // If there are remaining positive numbers
        while (p < pos.size()) {
            arr[i++] = pos[p++];
        }

        // If there are remaining negative numbers
        while (n < neg.size()) {
            arr[i++] = neg[n++];
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string input;
        cin.ignore();
        getline(cin, input);
        vector<int> arr;
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution().rearrange(arr);

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
