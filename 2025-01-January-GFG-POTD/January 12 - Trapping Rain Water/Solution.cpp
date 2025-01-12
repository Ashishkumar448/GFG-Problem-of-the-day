#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    totalWater += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    totalWater += rightMax - arr[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin.ignore(); // To handle newline after integer input
        string input;
        getline(cin, input);

        vector<int> arr;
        stringstream ss(input);
        string temp;
        while (getline(ss, temp, ' ')) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        cout << obj.maxWater(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
