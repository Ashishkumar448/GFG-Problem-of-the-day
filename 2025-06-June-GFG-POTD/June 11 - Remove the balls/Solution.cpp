#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& color, vector<int>& radius) {
        stack<pair<int, int>> stk;

        for (int i = 0; i < color.size(); i++) {
            if (!stk.empty() && stk.top().first == color[i] && stk.top().second == radius[i]) {
                stk.pop(); // Remove matching pair
            } else {
                stk.push({color[i], radius[i]});
            }
        }

        return stk.size(); // Remaining balls
    }
};
