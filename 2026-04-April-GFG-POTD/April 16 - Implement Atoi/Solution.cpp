class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) return 0;
        
        // 2. Check sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Read digits
        long long result = 0;
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            result = result * 10 + digit;
            
            // 4. Handle overflow
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return (int)(sign * result);
    }
