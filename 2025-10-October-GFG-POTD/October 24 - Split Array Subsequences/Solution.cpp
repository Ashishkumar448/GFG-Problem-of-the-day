#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> count, endAt;

        // Step 1: Count frequency of each number
        for (int num : arr) {
            count[num]++;
        }

        // Step 2: Traverse and form subsequences
        for (int num : arr) {
            if (count[num] == 0) continue;

            // Case 1: Extend an existing subsequence ending at num - 1
            if (endAt[num - 1] > 0) {
                endAt[num - 1]--;
                endAt[num]++;
                count[num]--;
            } 
            // Case 2: Start a new subsequence of length k
            else {
                bool possible = true;
                for (int i = 0; i < k; i++) {
                    if (count[num + i] <= 0) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) return false;

                for (int i = 0; i < k; i++) {
                    count[num + i]--;
                }
                endAt[num + k - 1]++;
            }
        }

        return true;
    }
};

// Example usage
int main() {
    Solution s;
    vector<int> arr1 = {2,2,3,3,4,5};
    vector<int> arr2 = {1,1,1,1,1};
    cout << boolalpha;
    cout << s.isPossible(arr1, 2) << endl; // true
    cout << s.isPossible(arr2, 4) << endl; // false
}
