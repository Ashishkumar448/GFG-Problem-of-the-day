class Solution {
public:
    vector<string> findExpr(string s, int target) {
        vector<string> result;
        if (s.empty()) return result;
        backtrack(result, "", s, target, 0, 0, 0);
        sort(result.begin(), result.end()); // Lexicographically sort
        return result;
    }

private:
    void backtrack(vector<string>& result, string path, const string& num, int target, int pos, long eval, long multed) {
        if (pos == num.size()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break; // Skip numbers with leading zeros
            string curStr = num.substr(pos, i - pos + 1);
            long cur = stol(curStr);

            if (pos == 0) {
                backtrack(result, curStr, num, target, i + 1, cur, cur);
            } else {
                backtrack(result, path + "+" + curStr, num, target, i + 1, eval + cur, cur);
                backtrack(result, path + "-" + curStr, num, target, i + 1, eval - cur, -cur);
                backtrack(result, path + "*" + curStr, num, target, i + 1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
};
