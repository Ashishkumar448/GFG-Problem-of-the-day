class Solution:
    def countRevPairs(self, arr):
        return self.merge_sort_and_count(arr, 0, len(arr) - 1)

    def merge_sort_and_count(self, arr, left, right):
        if left >= right:
            return 0

        mid = (left + right) // 2
        count = self.merge_sort_and_count(arr, left, mid) \
              + self.merge_sort_and_count(arr, mid + 1, right)

        # Count cross reverse pairs
        j = mid + 1
        for i in range(left, mid + 1):
            while j <= right and arr[i] > 2 * arr[j]:
                j += 1
            count += (j - (mid + 1))

        self.merge(arr, left, mid, right)
        return count

    def merge(self, arr, left, mid, right):
        temp = []
        i, j = left, mid + 1

        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                j += 1

        while i <= mid:
            temp.append(arr[i])
            i += 1
        while j <= right:
            temp.append(arr[j])
            j += 1

        arr[left:right + 1] = temp
