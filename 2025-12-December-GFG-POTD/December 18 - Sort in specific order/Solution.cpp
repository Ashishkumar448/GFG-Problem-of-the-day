#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;

        // Separate odd and even numbers
        for (int num : arr) {
            if (num % 2 != 0)
                odd.push_back(num);
            else
                even.push_back(num);
        }

        // Sort odd in descending order
        sort(odd.begin(), odd.end(), greater<int>());

        // Sort even in ascending order
        sort(even.begin(), even.end());

        // Merge back into original array
        int index = 0;
        for (int num : odd)
            arr[index++] = num;
        for (int num : even)
            arr[index++] = num;
    }
};
