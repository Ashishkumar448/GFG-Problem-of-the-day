#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        if (arr.empty()) return 0;
        if (arr.size() == 1) return arr[0];
        
        int prev2 = 0, prev1 = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            int take = arr[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        stringstream ss(line);
        while (ss >> num) {
            arr.push_back(num);
        }
        
        Solution solution;
        cout << solution.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
