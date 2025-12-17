from typing import List

class Solution:
    def mergeOverlap(self, arr: List[List[int]]) -> List[List[int]]:
        result = []
        
        # Edge case
        if not arr:
            return result

        # Sort intervals by starting time
        arr.sort(key=lambda x: x[0])

        start, end = arr[0]

        for i in range(1, len(arr)):
            if arr[i][0] <= end:
                end = max(end, arr[i][1])
            else:
                result.append([start, end])
                start, end = arr[i]

        # Add the last interval
        result.append([start, end])

        return result
