class Solution:
    def intersectionWithDuplicates(self, a, b):
        # Use sets for uniqueness
        set_a = set(a)
        result_set = set()

        # Check for intersection with the second array
        for num in b:
            if num in set_a:
                result_set.add(num)

        # Return the result as a list
        return list(result_set)


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        # First array input
        a = list(map(int, input().strip().split()))

        # Second array input
        b = list(map(int, input().strip().split()))

        sol = Solution()
        res = sol.intersectionWithDuplicates(a, b)

        # Sort the result
        res.sort()

        # Print the result
        if not res:
            print("[]")
        else:
            print(" ".join(map(str, res)))

        print("~")
