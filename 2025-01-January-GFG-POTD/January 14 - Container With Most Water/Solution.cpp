#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int left = 0; // Left pointer
        int right = arr.size() - 1; // Right pointer
        int maxWater = 0; // To store the maximum water

        while (left < right) {
            // Calculate the water between the current pair of lines
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int currentWater = height * width;

            // Update the maximum water if the current one is greater
            maxWater = max(maxWater, currentWater);

            // Move the pointer pointing to the shorter line inward
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> arr;
        stringstream ss(line);
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        cout << obj.maxWater(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
