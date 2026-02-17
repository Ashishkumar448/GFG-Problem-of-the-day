class Solution:
    @staticmethod
    def canAttend(arr):
        # Sort meetings based on start time
        arr.sort(key=lambda x: x[0])
        
        # Check for overlap
        for i in range(1, len(arr)):
            if arr[i][0] < arr[i - 1][1]:
                return False  # Overlapping meetings
        
        return True  # No overlaps
