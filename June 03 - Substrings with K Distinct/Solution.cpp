#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubstr(string s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }

private:
    int countAtMostK(const string& s, int k) {
        int left = 0, res = 0;
        unordered_map<char, int> freqMap;

        for (int right = 0; right < s.length(); ++right) {
            freqMap[s[right]]++;

            while (freqMap.size() > k) {
                freqMap[s[left]]--;
                if (freqMap[s[left]] == 0)
                    freqMap.erase(s[left]);
                left++;
            }

            res += right - left + 1;
        }

        return res;
    }
};
