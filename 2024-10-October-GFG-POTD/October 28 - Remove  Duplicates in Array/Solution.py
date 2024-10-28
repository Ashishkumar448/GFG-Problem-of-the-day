from collections import OrderedDict

class Solution:
    def removeDuplicate(self, arr):
        # Using OrderedDict to remove duplicates and maintain insertion order
        unique_elements = list(OrderedDict.fromkeys(arr))
        return unique_elements

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        solution = Solution()
        result = solution.removeDuplicate(arr)
        print(" ".join(map(str, result)))
        print("~")
