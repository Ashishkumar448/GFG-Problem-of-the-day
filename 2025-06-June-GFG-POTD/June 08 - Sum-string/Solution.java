class Solution {
    public boolean isSumString(String s) {
        int n = s.length();
        // Try all pairs of first and second number
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                String num1 = s.substring(0, i);
                String num2 = s.substring(i, j);
                
                if (isValid(num1) && isValid(num2)) {
                    if (check(s.substring(j), num1, num2)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // Check if str is valid (no leading zeros unless it's '0')
    private boolean isValid(String str) {
        return !(str.length() > 1 && str.charAt(0) == '0');
    }

    // Recursive check
    private boolean check(String remaining, String num1, String num2) {
        String sum = addStrings(num1, num2);
        if (!remaining.startsWith(sum)) return false;
        if (remaining.equals(sum)) return true;
        return check(remaining.substring(sum.length()), num2, sum);
    }

    // Helper to add two numeric strings
    private String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        
        while (i >= 0 || j >= 0 || carry != 0) {
            int digit1 = i >= 0 ? num1.charAt(i--) - '0' : 0;
            int digit2 = j >= 0 ? num2.charAt(j--) - '0' : 0;
            int sum = digit1 + digit2 + carry;
            sb.append(sum % 10);
            carry = sum / 10;
        }
        return sb.reverse().toString();
    }
}
