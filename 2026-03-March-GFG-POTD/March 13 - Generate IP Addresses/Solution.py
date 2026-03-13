class Solution:
    
    def generateIp(self, s):
        result = []
        
        def backtrack(index, parts, current):
            
            # If 4 parts formed and string fully used
            if parts == 4 and index == len(s):
                result.append(current[:-1])  # remove last dot
                return
            
            if parts == 4 or index == len(s):
                return
            
            for length in range(1, 4):
                if index + length > len(s):
                    break
                
                segment = s[index:index+length]
                
                # Leading zero check
                if len(segment) > 1 and segment[0] == '0':
                    continue
                
                if int(segment) <= 255:
                    backtrack(index + length, parts + 1, current + segment + ".")
        
        backtrack(0, 0, "")
        return result
