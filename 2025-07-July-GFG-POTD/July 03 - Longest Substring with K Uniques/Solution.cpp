#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) return -1;

        unordered_map<char, int> map;
        int maxLength = -1;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            map[s[end]]++;

            while (map.size() > k) {
                map[s[start]]--;
                if (map[s[start]] == 0)
                    map.erase(s[start]);
                start++;
            }

            if (map.size() == k) {
                maxLength = max(maxLength, end - start + 1);
            }
        }

        return maxLength;
    }
};
