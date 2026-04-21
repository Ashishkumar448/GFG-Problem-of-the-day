class Solution:
    
    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)
    
    def pour(self, fromCap, toCap, d):
        from_jug = fromCap  # fill source
        to_jug = 0          # destination empty
        step = 1
        
        while from_jug != d and to_jug != d:
            transfer = min(from_jug, toCap - to_jug)
            to_jug += transfer
            from_jug -= transfer
            step += 1
            
            if from_jug == d or to_jug == d:
                break
            
            if from_jug == 0:
                from_jug = fromCap
                step += 1
            
            if to_jug == toCap:
                to_jug = 0
                step += 1
        
        return step
    
    def minSteps(self, m, n, d):
        if d > max(m, n):
            return -1
        
        if d % self.gcd(m, n) != 0:
            return -1
        
        return min(self.pour(m, n, d), self.pour(n, m, d))
