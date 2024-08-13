class Solution:
    def SumofMiddleElements(self, A: list[int], B: list[int]) -> int:
        n = len(A)
        merged = [0] * (2 * n)
        i, j, k = 0, 0, 0

        # Merge the two arrays
        while i < n and j < n:
            if A[i] <= B[j]:
                merged[k] = A[i]
                i += 1
            else:
                merged[k] = B[j]
                j += 1
            k += 1

        # If there are remaining elements in A
        while i < n:
            merged[k] = A[i]
            i += 1
            k += 1

        # If there are remaining elements in B
        while j < n:
            merged[k] = B[j]
            j += 1
            k += 1

        # Find the middle elements and return their sum
        middle1 = merged[n - 1]  # First middle element
        middle2 = merged[n]      # Second middle element

        return middle1 + middle2