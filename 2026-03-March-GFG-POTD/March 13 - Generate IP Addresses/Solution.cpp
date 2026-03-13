#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void backtrack(string &s, int index, int parts, string current, vector<string> &result){
        
        // If 4 parts formed and string fully used
        if(parts == 4 && index == s.length()){
            current.pop_back(); // remove last '.'
            result.push_back(current);
            return;
        }
        
        // Invalid cases
        if(parts == 4 || index == s.length())
            return;
        
        for(int len = 1; len <= 3 && index + len <= s.length(); len++){
            
            string segment = s.substr(index, len);
            
            // Leading zero check
            if(segment.length() > 1 && segment[0] == '0')
                continue;
            
            int value = stoi(segment);
            
            if(value <= 255){
                backtrack(s, index + len, parts + 1, current + segment + ".", result);
            }
        }
    }
    
    vector<string> generateIp(string s) {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }
};
