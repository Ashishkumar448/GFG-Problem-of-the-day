class Solution:
    def findExpr(self, s: str, target: int) -> list[str]:
        result = []
        self.backtrack(result, "", s, target, 0, 0, 0)
        result.sort()  # Lexicographically sort
        return result

    def backtrack(self, result, path, num, target, pos, eval_, multed):
        if pos == len(num):
            if eval_ == target:
                result.append(path)
            return

        for i in range(pos, len(num)):
            if i != pos and num[pos] == '0':
                break  # Skip numbers with leading zeros
            curStr = num[pos:i+1]
            cur = int(curStr)

            if pos == 0:
                self.backtrack(result, curStr, num, target, i + 1, cur, cur)
            else:
                self.backtrack(result, path + "+" + curStr, num, target, i + 1, eval_ + cur, cur)
                self.backtrack(result, path + "-" + curStr, num, target, i + 1, eval_ - cur, -cur)
                self.backtrack(result, path + "*" + curStr, num, target, i + 1, eval_ - multed + multed * cur, multed * cur)
