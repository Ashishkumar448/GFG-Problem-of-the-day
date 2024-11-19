#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the smallest element larger than nums[i] from the right
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the elements to the right of i
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    int tc;
    cin >> tc; // Number of test cases
    while (tc--) {
        vector<int> nums;
        string inputLine;
        cin.ignore(); // Ignore the newline
        getline(cin, inputLine);
        stringstream ss(inputLine);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution obj;
        obj.nextPermutation(nums); // Generate the next permutation

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
