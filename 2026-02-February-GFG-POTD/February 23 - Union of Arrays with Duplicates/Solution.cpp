#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int a[], int b[], int n, int m) {
        unordered_set<int> s;
        
        // Insert elements of array a
        for(int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        
        // Insert elements of array b
        for(int i = 0; i < m; i++) {
            s.insert(b[i]);
        }
        
        // Convert set to vector
        vector<int> result(s.begin(), s.end());
        return result;
    }
};
