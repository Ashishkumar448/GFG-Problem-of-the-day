class Solution:
    def sortIt(self, arr):
        odd = []
        even = []

        # Separate odd and even numbers
        for num in arr:
            if num % 2 != 0:
                odd.append(num)
            else:
                even.append(num)

        # Sort odd in descending order
        odd.sort(reverse=True)

        # Sort even in ascending order
        even.sort()

        # Merge back into original array
        index = 0
        for num in odd:
            arr[index] = num
            index += 1
        for num in even:
            arr[index] = num
            index += 1
