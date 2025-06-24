#include <string>
using namespace std;

class Solution {
public:
    string maxSubseq(string s, int k) {
        string res;
        for (char c : s) {
            while (k > 0 && !res.empty() && res.back() < c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        if (k > 0) {
            res = res.substr(0, res.size() - k);
        }
        return res;
    }
};
