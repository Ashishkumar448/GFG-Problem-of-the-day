#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countBalanced(vector<string>& arr) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<int, int> balanceCount;
        balanceCount[0] = 1; // Base case for balance starting at beginning

        int balance = 0;
        int result = 0;

        for (string& s : arr) {
            for (char ch : s) {
                if (vowels.count(ch)) {
                    balance += 1;
                } else {
                    balance -= 1;
                }
            }
            result += balanceCount[balance];
            balanceCount[balance]++;
        }

        return result;
    }
};
