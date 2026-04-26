class Solution:
    def commonElements(self, a, b, c):
        res = []
        
        i = j = k = 0
        
        while i < len(a) and j < len(b) and k < len(c):
            
            # If all three are equal
            if a[i] == b[j] == c[k]:
                # Avoid duplicates
                if not res or res[-1] != a[i]:
                    res.append(a[i])
                i += 1
                j += 1
                k += 1
            
            elif a[i] < b[j]:
                i += 1
            
            elif b[j] < c[k]:
                j += 1
            
            else:
                k += 1
        
        return res
