class Solution:
    def maxPartitions(self, s: str) -> int:
        # Step 1: Store last occurrence of each character
        lastOccurrence = {char: i for i, char in enumerate(s)}

        partitions = 0
        maxLast = 0

        # Step 2: Traverse and create partitions
        for i, char in enumerate(s):
            maxLast = max(maxLast, lastOccurrence[char])
            
            if i == maxLast:
                partitions += 1

        return partitions

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.maxPartitions(s))
        print("~")
