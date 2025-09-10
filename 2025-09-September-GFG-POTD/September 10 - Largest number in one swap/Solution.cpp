class Solution {
public:
    string largestSwap(string s) {
        int n = s.size();
        vector<int> rightmost(10, -1);

        // Store rightmost occurrence of each digit
        for (int i = 0; i < n; i++) {
            rightmost[s[i] - '0'] = i;
        }

        // Try to find the first place to swap
        for (int i = 0; i < n; i++) {
            int currDigit = s[i] - '0';

            for (int d = 9; d > currDigit; d--) {
                if (rightmost[d] > i) {
                    // Swap
                    swap(s[i], s[rightmost[d]]);
                    return s;
                }
            }
        }

        // If no swap improves the number
        return s;
    }
};
