class Solution:
    @staticmethod
    def decodeString(s: str) -> str:
        count_stack = []
        str_stack = []
        curr_str = []
        num = 0

        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)  # handle multi-digit numbers
            elif c == '[':
                count_stack.append(num)
                str_stack.append("".join(curr_str))
                curr_str = []
                num = 0
            elif c == ']':
                repeat = count_stack.pop()
                prev_str = str_stack.pop()
                curr_str = [prev_str + "".join(curr_str) * repeat]
            else:
                curr_str.append(c)

        return "".join(curr_str)
