#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> st;

        for (int num : arr) {
            bool add = true;

            while (!st.empty()) {
                int top = st.top();

                // Opposite signs
                if ((top > 0 && num < 0) || (top < 0 && num > 0)) {
                    st.pop();

                    if (abs(top) > abs(num)) {
                        num = top; // keep top
                    } 
                    else if (abs(top) < abs(num)) {
                        // keep num
                    } 
                    else {
                        add = false; // both removed
                        break;
                    }
                } else {
                    break;
                }
            }

            if (add) {
                st.push(num);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
