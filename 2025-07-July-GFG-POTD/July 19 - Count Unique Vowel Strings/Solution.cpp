#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int vowelCount(string s) {
        unordered_map<char, int> vowelCounts;
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};

        // Count occurrences of each vowel
        for (char ch : s) {
            if (vowelsSet.count(ch)) {
                vowelCounts[ch]++;
            }
        }

        if (vowelCounts.empty()) return 0;

        int choices = 1;
        for (auto& pair : vowelCounts) {
            choices *= pair.second;
        }

        int perm = factorial(vowelCounts.size());
        return choices * perm;
    }

private:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};
