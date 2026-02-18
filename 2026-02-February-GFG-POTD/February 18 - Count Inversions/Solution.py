class Solution:
    
    def inversionCount(self, arr):
        return self.mergeSort(arr, 0, len(arr) - 1)
    
    def mergeSort(self, arr, left, right):
        count = 0
        
        if left < right:
            mid = (left + right) // 2
            
            count += self.mergeSort(arr, left, mid)
            count += self.mergeSort(arr, mid + 1, right)
            count += self.merge(arr, left, mid, right)
        
        return count
    
    def merge(self, arr, left, mid, right):
        temp = []
        i, j = left, mid + 1
        count = 0
        
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                count += (mid - i + 1)  # Count inversions
                j += 1
        
        while i <= mid:
            temp.append(arr[i])
            i += 1
        
        while j <= right:
            temp.append(arr[j])
            j += 1
        
        # Copy back to original array
        arr[left:right+1] = temp
        
        return count
