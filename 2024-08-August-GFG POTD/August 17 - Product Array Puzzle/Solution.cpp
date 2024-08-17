#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> leftProduct(n), rightProduct(n), result(n);

        // Initialize the first element of leftProduct as 1
        leftProduct[0] = 1;
        for (int i = 1; i < n; i++) {
            leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
        }

        // Initialize the last element of rightProduct as 1
        rightProduct[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProduct[i] = nums[i + 1] * rightProduct[i + 1];
        }

        // Multiply leftProduct and rightProduct to get the result
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
        Solution ob;
        vector<long long> ans = ob.productExceptSelf(array);

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
