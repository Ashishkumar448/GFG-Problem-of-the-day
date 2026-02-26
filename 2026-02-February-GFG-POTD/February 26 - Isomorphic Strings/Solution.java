class Solution {
    public boolean areIsomorphic(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        char[] map1 = new char[26]; // s1 -> s2
        char[] map2 = new char[26]; // s2 -> s1
        
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            
            int index1 = c1 - 'a';
            int index2 = c2 - 'a';
            
            // If not yet mapped
            if (map1[index1] == 0 && map2[index2] == 0) {
                map1[index1] = c2;
                map2[index2] = c1;
            } 
            // If already mapped, check consistency
            else {
                if (map1[index1] != c2 || map2[index2] != c1) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
