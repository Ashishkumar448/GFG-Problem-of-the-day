class Solution:
    # Function to check if two strings are rotations of each other or not.
    def areRotations(self, s1, s2):
        # 1. Basic Length Check
        if len(s1) != len(s2):
            return False
            
        n = len(s1)
        if n == 0:
            return True

        # 2. Compute LPS (Longest Prefix Suffix) array for s2
        lps = [0] * n
        length = 0 
        i = 1
        
        while i < n:
            if s2[i] == s2[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
                    
        # 3. KMP Search on virtual (s1 + s1)
        j = 0 # index for s2
        i = 0 # index for s1 (virtual)
        
        while i < 2 * n:
            # Compare s2[j] with s1[i % n]
            if s2[j] == s1[i % n]:
                j += 1
                i += 1
                # If we have matched the entire s2 string
                if j == n:
                    return True
            else:
                # Mismatch after some matches
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
                    
        return False
