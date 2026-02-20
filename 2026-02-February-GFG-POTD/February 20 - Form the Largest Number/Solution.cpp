#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLargest(vector<int>& arr) {
        // Convert integers to string array
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Edge case: if largest element is "0"
        if (nums[0] == "0")
            return "0";

        // Build result
        string result = "";
        for (string &num : nums) {
            result += num;
        }

        return result;
    }
};
