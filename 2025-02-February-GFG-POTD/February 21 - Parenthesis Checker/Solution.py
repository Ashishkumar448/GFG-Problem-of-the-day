class Solution:
    def isBalanced(self, s: str) -> bool:
        stack = []
        bracket_map = {')': '(', '}': '{', ']': '['}

        for ch in s:
            if ch in bracket_map.values():
                stack.append(ch)
            elif ch in bracket_map.keys():
                if not stack or stack.pop() != bracket_map[ch]:
                    return False
        return not stack
