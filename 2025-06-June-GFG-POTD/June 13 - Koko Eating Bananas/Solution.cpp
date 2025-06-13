#include <vector>
using namespace std;

class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int left = 1;
        int right = 0;
        for (int num : arr) {
            right = max(right, num);
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int totalHours = 0;
            for (int num : arr) {
                totalHours += (num + mid - 1) / mid;
            }
            if (totalHours <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
