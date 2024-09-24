class Solution:
    # Function to find the smallest window in the string s consisting
    # of all the characters of string p.
    def smallestWindow(self, s: str, p: str) -> str:
        if len(s) < len(p):
            return "-1"  # If the length of p is greater than s, no solution exists

        # Frequency maps to store the count of characters in p and the current window in s
        pFreq = [0] * 256
        sFreq = [0] * 256

        # Fill frequency map for the pattern string p
        for ch in p:
            pFreq[ord(ch)] += 1

        # Initialize pointers for the sliding window
        start = 0
        minLen = float('inf')
        count = 0
        startIndex = -1  # To store the starting index of the smallest window

        # Traverse through string s
        for end in range(len(s)):
            # Include the current character in the window
            ch = s[end]
            sFreq[ord(ch)] += 1

            # If the current character's frequency in the window is less than or equal to its frequency in p
            if sFreq[ord(ch)] <= pFreq[ord(ch)]:
                count += 1

            # When all characters are matched (window is valid)
            if count == len(p):
                # Try to minimize the window by moving the start pointer
                while sFreq[ord(s[start])] > pFreq[ord(s[start])] or pFreq[ord(s[start])] == 0:
                    if sFreq[ord(s[start])] > pFreq[ord(s[start])]:
                        sFreq[ord(s[start])] -= 1
                    start += 1

                # Update the minimum window length and the start index of the smallest window
                windowLen = end - start + 1
                if windowLen < minLen:
                    minLen = windowLen
                    startIndex = start

        # If no valid window was found, return "-1"
        return "-1" if startIndex == -1 else s[startIndex: startIndex + minLen]

# Driver code
if __name__ == "__main__":
    test = int(input())
    for _ in range(test):
        s = input()
        t = input()

        solution = Solution()
        print(solution.smallestWindow(s, t))
