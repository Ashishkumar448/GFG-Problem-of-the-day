#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) {
            return result; // Return empty list if array is empty
        }

        // Step 1: Find potential candidates using Boyer-Moore Voting Algorithm
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Validate the candidates
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        int n = nums.size();
        if (count1 > n / 3) {
            result.push_back(candidate1);
        }
        if (count2 > n / 3) {
            result.push_back(candidate2);
        }

        // Sort the result before returning
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--) {
        string s;
        getline(cin, s);

        vector<int> nums;
        size_t pos = 0;
        while ((pos = s.find(" ")) != string::npos) {
            nums.push_back(stoi(s.substr(0, pos)));
            s.erase(0, pos + 1);
        }
        nums.push_back(stoi(s)); // Add the last number

        Solution ob;
        vector<int> ans = ob.findMajority(nums);

        if (ans.empty()) {
            cout << "[]" << endl;
        } else {
            for (int num : ans) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
