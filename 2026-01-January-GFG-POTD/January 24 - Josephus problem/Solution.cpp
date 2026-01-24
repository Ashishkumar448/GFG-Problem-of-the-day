class Solution {
public:
    int josephus(int n, int k) {
        int res = 0;  // 0-based index
        
        for (int i = 2; i <= n; i++) {
            res = (res + k) % i;
        }
        
        return res + 1; // convert to 1-based index
    }
};
