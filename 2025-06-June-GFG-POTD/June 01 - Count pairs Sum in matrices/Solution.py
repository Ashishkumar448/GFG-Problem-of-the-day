class Solution:
    def countPairs(self, mat1, mat2, x):
        n = len(mat1)
        s = set()

        # Step 1: Add all elements from mat2 to the set
        for i in range(n):
            for j in range(n):
                s.add(mat2[i][j])

        count = 0

        # Step 2: For each element in mat1, check if x - a is in set
        for i in range(n):
            for j in range(n):
                a = mat1[i][j]
                b = x - a
                if b in s:
                    count += 1

        return count
