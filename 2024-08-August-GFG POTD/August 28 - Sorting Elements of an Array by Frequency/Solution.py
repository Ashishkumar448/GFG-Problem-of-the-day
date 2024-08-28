from collections import defaultdict

class Solution:
    def sortByFreq(self, arr):
        # Step 1: Count frequencies
        frequency_map = defaultdict(int)
        for num in arr:
            frequency_map[num] += 1
        
        # Step 2: Create a list of tuples
        freq_list = [(key, value) for key, value in frequency_map.items()]
        
        # Step 3: Sort the list
        freq_list.sort(key=lambda x: (-x[1], x[0])) # Sort by frequency (descending), then by number (ascending)
        
        # Step 4: Build the result
        result = []
        for pair in freq_list:
            result.extend([pair[0]] * pair[1])
        
        return result

if __name__ == "__main__":
    n = int(input())
    while n > 0:
        arr = list(map(int, input().split()))
        sol = Solution()
        ans = sol.sortByFreq(arr)
        print(" ".join(map(str, ans)))
        n -= 1
