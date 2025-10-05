class Solution {
    public ArrayList<String> findExpr(String s, int target) {
        ArrayList<String> result = new ArrayList<>();
        if (s == null || s.length() == 0) return result;
        backtrack(result, "", s, target, 0, 0, 0);
        Collections.sort(result); // Ensure lexicographically sorted
        return result;
    }

    private void backtrack(ArrayList<String> result, String path, String num, int target, int pos, long eval, long multed) {
        if (pos == num.length()) {
            if (eval == target) {
                result.add(path);
            }
            return;
        }

        for (int i = pos; i < num.length(); i++) {
            // Avoid numbers with leading zeros
            if (i != pos && num.charAt(pos) == '0') break;
            String curStr = num.substring(pos, i + 1);
            long cur = Long.parseLong(curStr);

            if (pos == 0) {
                // First number, pick without any operator
                backtrack(result, path + curStr, num, target, i + 1, cur, cur);
            } else {
                // Addition
                backtrack(result, path + "+" + curStr, num, target, i + 1, eval + cur, cur);
                // Subtraction
                backtrack(result, path + "-" + curStr, num, target, i + 1, eval - cur, -cur);
                // Multiplication (handle precedence)
                backtrack(result, path + "*" + curStr, num, target, i + 1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
}
