class Solution:
    @staticmethod
    def caseSort(s: str) -> str:
        upper = []
        lower = []

        # Separate characters by case
        for c in s:
            if c.isupper():
                upper.append(c)
            else:
                lower.append(c)

        # Sort both lists
        upper.sort()
        lower.sort()

        # Reconstruct the result
        result = []
        i = j = 0

        for c in s:
            if c.isupper():
                result.append(upper[i])
                i += 1
            else:
                result.append(lower[j])
                j += 1

        return ''.join(result)
