class Solution:
    @staticmethod
    def minChar(s: str) -> int:
        # Concatenate original string, $, and reversed string
        concatenated = s + "$" + s[::-1]
        n = len(concatenated)

        # Build LPS array
        lps = [0] * n
        length = 0
        i = 1
        
        while i < n:
            if concatenated[i] == concatenated[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        # Length of the longest palindromic suffix in original string
        longest_palindromic_suffix = lps[-1]
        
        # Minimum characters to add at the front
        return len(s) - longest_palindromic_suffix

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        print(Solution.minChar(s))
        print("~")
