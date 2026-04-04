class Solution:
    def graycode(self, n):
        result = ["0"]
        
        # Base case
        if n == 1:
            result.append("1")
            return result
        
        result.append("1")
        
        # Build from 2 to n
        for i in range(2, n + 1):
            size = len(result)
            
            # Step 1: Add reversed elements
            for j in range(size - 1, -1, -1):
                result.append(result[j])
            
            # Step 2: Add '0' prefix to first half
            for j in range(size):
                result[j] = "0" + result[j]
            
            # Step 3: Add '1' prefix to second half
            for j in range(size, len(result)):
                result[j] = "1" + result[j]
        
        return result
