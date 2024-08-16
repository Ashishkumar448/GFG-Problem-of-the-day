#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int maximizeCuts(int n, int x, int y, int z) {
        // Creating a dp array with size n+1 and initializing with -1
        vector<int> dp(n + 1, -1);
        
        // Base case: 0 length segment can have 0 cuts
        dp[0] = 0;
        
        // Filling the dp array
        for (int i = 1; i <= n; i++) {
            if (i >= x && dp[i - x] != -1) 
                dp[i] = max(dp[i], dp[i - x] + 1);
            if (i >= y && dp[i - y] != -1) 
                dp[i] = max(dp[i], dp[i - y] + 1);
            if (i >= z && dp[i - z] != -1) 
                dp[i] = max(dp[i], dp[i - z] + 1);
        }
        
        // If dp[n] is still -1, no cuts could be made, so return 0
        return dp[n] == -1 ? 0 : dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int x, y, z;
        cin >> x >> y >> z;
        
        Solution obj;
        cout << obj.maximizeCuts(n, x, y, z) << endl;
    }
    
    return 0;
}
