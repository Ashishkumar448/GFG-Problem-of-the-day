class Solution:
    def reducePairs(self, arr):
        stack = []

        for num in arr:
            add = True

            while stack:
                top = stack[-1]

                # Opposite signs
                if (top > 0 and num < 0) or (top < 0 and num > 0):
                    stack.pop()

                    if abs(top) > abs(num):
                        num = top
                    elif abs(top) < abs(num):
                        pass
                    else:
                        add = False
                        break
                else:
                    break

            if add:
                stack.append(num)

        return stack
