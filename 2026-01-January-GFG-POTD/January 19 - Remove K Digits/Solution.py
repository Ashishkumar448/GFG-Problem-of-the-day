class Solution:
    def removeKdig(self, s: str, k: int) -> str:
        stack = []

        for c in s:
            # Remove larger digits from stack if possible
            while stack and k > 0 and stack[-1] > c:
                stack.pop()
                k -= 1
            stack.append(c)

        # If k digits still need to be removed, remove from end
        while k > 0 and stack:
            stack.pop()
            k -= 1

        # Build result string
        result = ''.join(stack).lstrip('0')

        # If empty, return "0"
        return result if result else "0"
