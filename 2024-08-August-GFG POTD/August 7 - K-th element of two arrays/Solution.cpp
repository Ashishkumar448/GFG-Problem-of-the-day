#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        vector<int> result(arr1.size() + arr2.size());
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), result.begin());
        sort(result.begin(), result.end());
        return result[k - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int k;
        cin >> k;

        int n1;
        cin >> n1;
        vector<int> arr1(n1);
        for (int i = 0; i < n1; i++) {
            cin >> arr1[i];
        }

        int n2;
        cin >> n2;
        vector<int> arr2(n2);
        for (int i = 0; i < n2; i++) {
            cin >> arr2[i];
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
