#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalElements(vector<int>& arr) {
        int left = 0;
        int maxLength = 0;
        unordered_map<int, int> freq;
        
        for (int right = 0; right < arr.size(); right++) {
            // Add current element
            freq[arr[right]]++;
            
            // Shrink window if more than 2 distinct elements
            while (freq.size() > 2) {
                freq[arr[left]]--;
                
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                
                left++;
            }
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
