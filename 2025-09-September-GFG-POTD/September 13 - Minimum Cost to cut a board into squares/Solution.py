class Solution:
    @staticmethod
    def minCost(n, m, x, y):
        # Sort in descending order
        x.sort(reverse=True)
        y.sort(reverse=True)

        i = j = 0
        vertical_segments = 1
        horizontal_segments = 1
        cost = 0

        while i < len(x) and j < len(y):
            if x[i] >= y[j]:
                # vertical cut
                cost += x[i] * horizontal_segments
                vertical_segments += 1
                i += 1
            else:
                # horizontal cut
                cost += y[j] * vertical_segments
                horizontal_segments += 1
                j += 1

        while i < len(x):
            cost += x[i] * horizontal_segments
            i += 1

        while j < len(y):
            cost += y[j] * vertical_segments
            j += 1

        return cost
