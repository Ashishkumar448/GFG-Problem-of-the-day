class Solution:
    def search(self, pat, txt):
        result = []
        M = len(pat)  # Length of pattern
        N = len(txt)  # Length of text

        # Step 1: Create the LPS array for the pattern
        lps = self.computeLPSArray(pat, M)

        # Step 2: Use LPS array to search the pattern in the text
        i = 0  # Index for txt
        j = 0  # Index for pat
        
        while i < N:
            if pat[j] == txt[i]:
                i += 1
                j += 1
            if j == M:  # Found a match
                result.append(i - j)
                j = lps[j - 1]
            elif i < N and pat[j] != txt[i]:  # Mismatch after j matches
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return result

    def computeLPSArray(self, pat, M):
        lps = [0] * M
        length = 0  # Length of the previous longest prefix suffix
        i = 1
        
        # Calculate lps[i] for i = 1 to M-1
        while i < M:
            if pat[i] == pat[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        txt = input()
        pat = input()
        ob = Solution()
        res = ob.search(pat, txt)
        if not res:
            print("[]")
        else:
            print(*res)
