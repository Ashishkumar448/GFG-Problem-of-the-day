#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static vector<int> subsetXOR(int n) {
        vector<int> ans;
        
        // XOR of 1 to n
        int t = 0;
        for (int i = 1; i <= n; i++)
            t ^= i;

        // Case 1: XOR already equals n → include all
        if (t == n) {
            for (int i = 1; i <= n; i++)
                ans.push_back(i);
            return ans;
        }

        int x = t ^ n;  // value to remove if possible

        // Case 2: removing a single number x works
        if (x >= 1 && x <= n) {
            for (int i = 1; i <= n; i++) {
                if (i != x) ans.push_back(i);
            }
            return ans;
        }

        // Case 3: need to remove two numbers a and b with a ^ b = x
        int a = -1, b = -1;
        for (int i = n; i >= 1; i--) {
            int j = i ^ x;
            if (j >= 1 && j <= n && j != i) {
                a = i;
                b = j;
                break;
            }
        }

        // Add all except a and b
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b) ans.push_back(i);
        }

        return ans;
    }
};
