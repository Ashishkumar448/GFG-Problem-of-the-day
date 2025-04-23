class Solution:
    def singleNum(self, arr):
        xor_all = 0

        # Step 1: XOR all elements
        for num in arr:
            xor_all ^= num

        # Step 2: Find rightmost set bit
        set_bit = xor_all & -xor_all

        num1 = 0
        num2 = 0

        # Step 3: Divide into two groups and XOR separately
        for num in arr:
            if num & set_bit:
                num1 ^= num
            else:
                num2 ^= num

        # Step 4: Return in increasing order
        return sorted([num1, num2])


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        sol = Solution()
        result = sol.singleNum(arr)
        print(*result)
        print("~")
