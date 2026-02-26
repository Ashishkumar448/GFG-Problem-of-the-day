class Solution:
    def areIsomorphic(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        
        map1 = [''] * 26  # s1 -> s2
        map2 = [''] * 26  # s2 -> s1
        
        for c1, c2 in zip(s1, s2):
            index1 = ord(c1) - ord('a')
            index2 = ord(c2) - ord('a')
            
            # If not yet mapped
            if map1[index1] == '' and map2[index2] == '':
                map1[index1] = c2
                map2[index2] = c1
            # If already mapped, check consistency
            else:
                if map1[index1] != c2 or map2[index2] != c1:
                    return False
        
        return True
