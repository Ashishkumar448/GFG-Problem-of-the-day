from collections import defaultdict

class Solution:
    def countPairsWithDiffK(self, arr, k):
        freq_map = defaultdict(int)
        
        # Fill the frequency map
        for num in arr:
            freq_map[num] += 1
        
        count = 0
        
        # Iterate over each unique element in the map
        for num in freq_map:
            if k == 0:
                # Special case: count pairs of the same element if k is 0
                freq = freq_map[num]
                count += (freq * (freq - 1)) // 2
            else:
                # Check if num + k is in the map and add valid pairs
                if num + k in freq_map:
                    count += freq_map[num] * freq_map[num + k]
        
        return count

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        line = input().strip()
        arr = list(map(int, line.split()))
        k = int(input().strip())
        
        ob = Solution()
        ans = ob.countPairsWithDiffK(arr, k)
        print(ans)
        print("~")
