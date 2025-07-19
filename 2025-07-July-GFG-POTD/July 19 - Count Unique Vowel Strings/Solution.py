class Solution:
    def vowelCount(self, s: str) -> int:
        from math import factorial

        vowels_set = {'a', 'e', 'i', 'o', 'u'}
        vowel_counts = {}

        for ch in s:
            if ch in vowels_set:
                vowel_counts[ch] = vowel_counts.get(ch, 0) + 1

        if not vowel_counts:
            return 0

        choices = 1
        for count in vowel_counts.values():
            choices *= count

        perm = factorial(len(vowel_counts))
        return choices * perm
