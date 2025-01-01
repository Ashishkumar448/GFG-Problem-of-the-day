class Solution:
    def anagrams(self, arr):
        # Map to group anagrams
        anagram_map = {}

        # Group strings by sorted characters
        for word in arr:
            sorted_word = ''.join(sorted(word))
            if sorted_word not in anagram_map:
                anagram_map[sorted_word] = []
            anagram_map[sorted_word].append(word)

        # Collect all groups from the map
        result = list(anagram_map.values())
        return result


if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = input().split()

        ob = Solution()
        result = ob.anagrams(arr)

        # Sort result based on the first word in each group
        result.sort(key=lambda x: x[0])

        # Print the result
        for group in result:
            print(" ".join(group))
        print("~")
