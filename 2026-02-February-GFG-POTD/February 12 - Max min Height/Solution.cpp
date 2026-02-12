#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        
        int low = INT_MAX;
        for (int h : arr) {
            low = min(low, h);
        }
        
        int high = low + k;
        int ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
private:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        long long added = 0;
        long long used = 0;
        
        for (int i = 0; i < n; i++) {
            added += diff[i];
            
            long long currentHeight = arr[i] + added;
            
            if (currentHeight < target) {
                long long need = target - currentHeight;
                used += need;
                
                if (used > k) return false;
                
                added += need;
                if (i + w < diff.size())
                    diff[i + w] -= need;
            }
        }
        
        return true;
    }
};
