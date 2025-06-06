class Solution:
    def search(self, pat: str, txt: str):
        result = []
        m = len(pat)
        n = len(txt)
        d = 256  # Number of characters in the input alphabet
        q = 101  # A prime number
        h = 1
        p = 0  # Hash for pattern
        t = 0  # Hash for text

        # Calculate h = pow(d, m-1) % q
        for i in range(m - 1):
            h = (h * d) % q

        # Initial hash values
        for i in range(m):
            p = (d * p + ord(pat[i])) % q
            t = (d * t + ord(txt[i])) % q

        # Slide pattern over text
        for i in range(n - m + 1):
            if p == t:
                if txt[i:i + m] == pat:
                    result.append(i + 1)  # 1-based indexing

            if i < n - m:
                t = (d * (t - ord(txt[i]) * h) + ord(txt[i + m])) % q
                if t < 0:
                    t += q

        return result
