class Solution:
    def findMajority(self, arr):
        n = len(arr)
        count1 = 0
        count2 = 0
        candidate1 = 0
        candidate2 = 1  # Different from candidate1

        # Step 1: Find potential candidates
        for num in arr:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        # Step 2: Verify the candidates
        count1 = count2 = 0
        for num in arr:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1

        # Step 3: Collect valid candidates
        result = []
        if count1 > n // 3:
            result.append(candidate1)
        if count2 > n // 3:
            result.append(candidate2)

        return sorted(result)
