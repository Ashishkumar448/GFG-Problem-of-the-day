// C++ solution using XOR
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int xorArr = 0, xorRange = 0;

        for (int num : arr)
            xorArr ^= num;

        for (int i = 1; i <= n - 1; i++)
            xorRange ^= i;

        return xorArr ^ xorRange;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        vector<int> arr;
        int num;
        istringstream iss(line);
        while (iss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findDuplicate(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
