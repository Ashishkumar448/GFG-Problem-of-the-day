from collections import deque

class Solution:
    def catchThieves(self, arr, k):
        n = len(arr)
        count = 0

        police = deque()
        thief = deque()

        for i in range(n):
            if arr[i] == 'P':
                police.append(i)
            elif arr[i] == 'T':
                thief.append(i)

            while police and thief:
                polIndex = police[0]
                thiefIndex = thief[0]

                if abs(polIndex - thiefIndex) <= k:
                    count += 1
                    police.popleft()
                    thief.popleft()
                elif thiefIndex < polIndex:
                    thief.popleft()
                else:
                    police.popleft()

        return count
