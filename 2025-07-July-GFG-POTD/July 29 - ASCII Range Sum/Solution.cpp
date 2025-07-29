#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    std::vector<int> asciirange(std::string s) {
        std::vector<int> result;
        std::unordered_set<char> seen;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (seen.count(ch)) continue;

            int first = s.find(ch);
            int last = s.rfind(ch);

            if (first != last) {
                int sum = 0;
                for (int j = first + 1; j < last; j++) {
                    sum += static_cast<int>(s[j]);
                }
                if (sum > 0) {
                    result.push_back(sum);
                }
            }
            seen.insert(ch);
        }

        return result;
    }
};
