from collections import defaultdict
from sortedcontainers import SortedDict

class Solution:
    def sumOfModes(self, arr, k: int) -> int:
        n = len(arr)
        freq = defaultdict(int)
        groups = SortedDict()  # freq -> set of values

        def addElement(x):
            oldCount = freq[x]
            newCount = oldCount + 1
            freq[x] = newCount

            if oldCount > 0:
                groups[oldCount].discard(x)
                if not groups[oldCount]:
                    del groups[oldCount]

            if newCount not in groups:
                groups[newCount] = set()
            groups[newCount].add(x)

        def removeElement(x):
            oldCount = freq[x]
            newCount = oldCount - 1

            groups[oldCount].discard(x)
            if not groups[oldCount]:
                del groups[oldCount]

            if newCount == 0:
                del freq[x]
            else:
                freq[x] = newCount
                if newCount not in groups:
                    groups[newCount] = set()
                groups[newCount].add(x)

        # build first window
        for i in range(k):
            addElement(arr[i])

        total = 0

        # process windows
        for i in range(k, n + 1):
            maxFreq = groups.peekitem(-1)[0]  # largest key
            mode = min(groups[maxFreq])       # smallest element in that freq
            total += mode

            if i < n:
                removeElement(arr[i - k])
                addElement(arr[i])

        return total
