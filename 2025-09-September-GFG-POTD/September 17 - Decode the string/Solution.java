class Solution {
    static String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        StringBuilder currStr = new StringBuilder();
        int num = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');  // handle multi-digit numbers
            } else if (c == '[') {
                countStack.push(num);
                strStack.push(currStr);
                currStr = new StringBuilder();
                num = 0;
            } else if (c == ']') {
                int repeat = countStack.pop();
                StringBuilder prevStr = strStack.pop();
                for (int i = 0; i < repeat; i++) {
                    prevStr.append(currStr);
                }
                currStr = prevStr;
            } else {
                currStr.append(c);
            }
        }

        return currStr.toString();
    }
}
