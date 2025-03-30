#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, startIndex = 0, currentGas = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            if (currentGas < 0) {
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> gas, cost;
        int n, val;

        // Read gas stations
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> val;
            gas.push_back(val);
        }

        // Read cost array
        for (int i = 0; i < n; i++) {
            cin >> val;
            cost.push_back(val);
        }

        Solution obj;
        cout << obj.startStation(gas, cost) << endl;
        cout << "~" << endl;
    }
    return 0;
}
