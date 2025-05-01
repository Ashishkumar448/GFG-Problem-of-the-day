#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row;
        int mod = 1000000007;

        long val = 1;
        row.push_back((int)val);

        for (int k = 1; k < n; k++) {
            val = val * (n - k);
            val = val / k;
            val %= mod;
            row.push_back((int)val);
        }

        return row;
    }
};

void printAns(vector<int>& ans) {
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        vector<int> ans = obj.nthRowOfPascalTriangle(n);
        printAns(ans);
        cout << "~" << endl;
    }

    return 0;
}
