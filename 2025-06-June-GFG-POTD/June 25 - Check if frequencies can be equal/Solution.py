from collections import Counter

class Solution:
    def sameFreq(self, s: str) -> bool:
        freq_map = Counter(s)

        # Step 2: Count frequencies of frequencies
        freq_count = Counter(freq_map.values())

        # Case 1: All frequencies same
        if len(freq_count) == 1:
            return True

        # Case 2: Only two different frequencies
        if len(freq_count) == 2:
            keys = list(freq_count.keys())
            f1, f2 = keys[0], keys[1]
            c1, c2 = freq_count[f1], freq_count[f2]

            # Case A: one frequency is 1 and occurs once
            if (f1 == 1 and c1 == 1) or (f2 == 1 and c2 == 1):
                return True

            # Case B: frequencies differ by 1 and higher freq occurs once
            if abs(f1 - f2) == 1:
                if (f1 > f2 and c1 == 1) or (f2 > f1 and c2 == 1):
                    return True

        return False
