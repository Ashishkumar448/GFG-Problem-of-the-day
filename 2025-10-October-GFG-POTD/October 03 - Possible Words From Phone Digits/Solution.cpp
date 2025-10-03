#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> KEYPAD = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(vector<int>& arr, int index, string& current, vector<string>& result) {
        if (index == arr.size()) {
            if (!current.empty()) result.push_back(current);
            return;
        }

        string letters = KEYPAD[arr[index]];
        if (letters.empty()) {
            // skip digits 0 and 1
            backtrack(arr, index + 1, current, result);
            return;
        }

        for (char c : letters) {
            current.push_back(c);
            backtrack(arr, index + 1, current, result);
            current.pop_back(); // backtrack
        }
    }

public:
    vector<string> possibleWords(vector<int>& arr) {
        vector<string> result;
        string current;
        backtrack(arr, 0, current, result);
        return result;
    }
};

// Example usage
/*
int main() {
    Solution sol;
    vector<int> arr = {8, 8, 1};
    vector<string> res = sol.possibleWords(arr);
    for (auto &s : res) cout << s << " ";
    return 0;
}
*/
