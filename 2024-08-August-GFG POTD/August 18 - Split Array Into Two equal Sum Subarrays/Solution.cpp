#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : arr) {
            totalSum += num;
        }
        
        // If the total sum is odd, we can't split it into two equal parts
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int halfSum = totalSum / 2;
        int runningSum = 0;
        
        // Iterate through the array and check if we can find a split
        for (int num : arr) {
            runningSum += num;
            if (runningSum == halfSum) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
