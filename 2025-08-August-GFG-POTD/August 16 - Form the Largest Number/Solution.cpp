#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLargest(vector<int>& arr) {
        // Step 1: Convert int to string
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Step 2: Sort using custom comparator
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b); // descending order
        });

        // Step 3: Handle leading zeros
        if (nums[0] == "0") {
            return "0";
        }

        // Step 4: Build the result
        string result;
        for (string &num : nums) {
            result += num;
        }
        return result;
    }
};
