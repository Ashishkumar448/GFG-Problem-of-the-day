class Solution:
    def countStrings(self, n):
        if n == 1:
            return 2
        
        a = 2  # f(1)
        b = 3  # f(2)
        
        for i in range(3, n + 1):
            c = a + b
            a = b
            b = c
        
        return b
