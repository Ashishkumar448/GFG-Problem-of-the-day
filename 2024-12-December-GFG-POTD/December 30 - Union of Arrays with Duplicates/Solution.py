class Solution:
    def findUnion(self, a, b):
        # Use a set to store the union of the arrays
        union_set = set()

        # Add elements of array 'a' to the set
        union_set.update(a)

        # Add elements of array 'b' to the set
        union_set.update(b)

        # The size of the set represents the number of distinct elements
        return len(union_set)

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1

        # Reading the first array
        a = list(map(int, input().split()))

        # Reading the second array
        b = list(map(int, input().split()))

        # Creating an instance of the Solution class
        ob = Solution()

        # Calling findUnion method and printing the result
        print(ob.findUnion(a, b))
