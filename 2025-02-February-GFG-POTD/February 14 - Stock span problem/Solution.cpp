// C++ Implementation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> result;
        stack<int> stack;
        
        for (int i = 0; i < arr.size(); i++) {
            while (!stack.empty() && arr[stack.top()] <= arr[i]) {
                stack.pop();
            }
            
            if (stack.empty()) {
                result.push_back(i + 1);
            } else {
                result.push_back(i - stack.top());
            }
            
            stack.push(i);
        }
        
        return result;
    }
};
