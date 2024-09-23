# Driver code
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        s = input()
        ob = Solution()
        print(ob.lps(s))
        t -= 1

# User function template for Python
class Solution:
    def lps(self, str):
        # code here
        n = len(str)
        lpsArray = [0] * n

        length = 0  # length of previous longest prefix suffix
        i = 1

        # LPS[0] is always 0, no proper prefix or suffix for single character
        lpsArray[0] = 0

        while i < n:
            if str[i] == str[length]:
                length += 1
                lpsArray[i] = length
                i += 1
            else:
                if length != 0:
                    # Try finding shorter prefix
                    length = lpsArray[length - 1]
                else:
                    lpsArray[i] = 0
                    i += 1

        # Return the last value in the lpsArray which represents the longest prefix suffix
        return lpsArray[n - 1]
