#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::vector<int> findGreater(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> res;
        std::stack<int> st;
        std::unordered_map<int, int> freqMap;

        // Step 1: Count frequencies
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int curr = arr[i];

            // Pop while top has freq <= current
            while (!st.empty() && freqMap[st.top()] <= freqMap[curr]) {
                st.pop();
            }

            if (st.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(st.top());
            }

            st.push(curr);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
