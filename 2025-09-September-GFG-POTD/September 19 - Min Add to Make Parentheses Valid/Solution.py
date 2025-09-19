class Solution:
    def minParentheses(self, s: str) -> int:
        balance = 0     # track open '('
        insertions = 0  # track extra needed
        
        for c in s:
            if c == '(':
                balance += 1
            else:  # c == ')'
                if balance > 0:
                    balance -= 1  # match with '('
                else:
                    insertions += 1  # need an extra '('
        
        # add remaining unmatched '('
        return insertions + balance
