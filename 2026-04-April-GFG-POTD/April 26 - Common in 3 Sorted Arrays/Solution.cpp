#include <vector>
using namespace std;

class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> res;
        
        int i = 0, j = 0, k = 0;
        
        while (i < a.size() && j < b.size() && k < c.size()) {
            
            // If all three are equal
            if (a[i] == b[j] && b[j] == c[k]) {
                // Avoid duplicates
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++; j++; k++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else {
                k++;
            }
        }
        
        return res;
    }
};
