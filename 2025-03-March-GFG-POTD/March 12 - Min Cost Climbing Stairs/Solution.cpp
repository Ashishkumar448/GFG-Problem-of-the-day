#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        int prev2 = cost[0], prev1 = cost[1], curr = 0;

        for (int i = 2; i < n; i++) {
            curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        vector<int> cost;
        string input;
        cin.ignore();
        getline(cin, input);

        int num;
        stringstream ss(input);
        while (ss >> num) {
            cost.push_back(num);
        }

        Solution obj;
        cout << obj.minCostClimbingStairs(cost) << endl;
        cout << "~" << endl;
    }

    return 0;
}
