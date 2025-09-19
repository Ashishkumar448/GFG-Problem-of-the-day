class Solution {
public:
    int minParentheses(string s) {
        int balance = 0;     // track open '('
        int insertions = 0;  // track extra needed
        
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // c == ')'
                if (balance > 0) {
                    balance--;  // match with '('
                } else {
                    insertions++; // need an extra '('
                }
            }
        }
        
        // add remaining unmatched '('
        return insertions + balance;
    }
};
