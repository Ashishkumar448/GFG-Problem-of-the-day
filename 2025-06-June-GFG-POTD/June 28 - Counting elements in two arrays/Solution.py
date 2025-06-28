from bisect import bisect_right

class Solution:
    @staticmethod
    def countLessEq(a, b):
        result = []
        
        # Step 1: Sort array b
        b.sort()
        
        # Step 2: For each element in a, use bisect_right
        for num in a:
            count = bisect_right(b, num)
            result.append(count)
        
        return result
