from collections import deque

class Solution:
    def stableMarriage(self, men, women):
        n = len(men)

        wifeOfMan = [-1] * n
        husbandOfWoman = [-1] * n
        nextProposal = [0] * n

        # rank[w][m] = preference rank of man m for woman w
        rank = [[0] * n for _ in range(n)]
        for w in range(n):
            for i in range(n):
                rank[w][women[w][i]] = i

        freeMen = deque(range(n))

        while freeMen:
            m = freeMen.popleft()

            w = men[m][nextProposal[m]]
            nextProposal[m] += 1

            if husbandOfWoman[w] == -1:
                # Woman is free
                husbandOfWoman[w] = m
                wifeOfMan[m] = w
            else:
                currentMan = husbandOfWoman[w]

                if rank[w][m] < rank[w][currentMan]:
                    # Woman prefers new man
                    husbandOfWoman[w] = m
                    wifeOfMan[m] = w

                    # Old man becomes free
                    wifeOfMan[currentMan] = -1
                    freeMen.append(currentMan)
                else:
                    # Woman rejects proposal
                    freeMen.append(m)

        return wifeOfMan
