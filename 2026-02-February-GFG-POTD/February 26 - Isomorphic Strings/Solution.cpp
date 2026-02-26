class Solution {
public:
    bool areIsomorphic(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        
        vector<char> map1(26, 0); // s1 -> s2
        vector<char> map2(26, 0); // s2 -> s1
        
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            int index1 = c1 - 'a';
            int index2 = c2 - 'a';
            
            // If not yet mapped
            if (map1[index1] == 0 && map2[index2] == 0) {
                map1[index1] = c2;
                map2[index2] = c1;
            }
            // If already mapped, check consistency
            else {
                if (map1[index1] != c2 || map2[index2] != c1)
                    return false;
            }
        }
        
        return true;
    }
};
