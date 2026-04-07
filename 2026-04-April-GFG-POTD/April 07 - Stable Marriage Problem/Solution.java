class Solution {
    public int[] stableMarriage(int[][] men, int[][] women) {
        int n = men.length;

        int[] wifeOfMan = new int[n];
        int[] husbandOfWoman = new int[n];
        int[] nextProposal = new int[n];

        Arrays.fill(wifeOfMan, -1);
        Arrays.fill(husbandOfWoman, -1);

        // rank[w][m] = preference rank of man m for woman w
        int[][] rank = new int[n][n];
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        Queue<Integer> freeMen = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            freeMen.add(i);
        }

        while (!freeMen.isEmpty()) {
            int m = freeMen.poll();

            int w = men[m][nextProposal[m]];
            nextProposal[m]++;

            if (husbandOfWoman[w] == -1) {
                // Woman is free
                husbandOfWoman[w] = m;
                wifeOfMan[m] = w;
            } else {
                int currentMan = husbandOfWoman[w];

                // Check preference
                if (rank[w][m] < rank[w][currentMan]) {
                    // Woman prefers new man
                    husbandOfWoman[w] = m;
                    wifeOfMan[m] = w;

                    // Old man becomes free
                    wifeOfMan[currentMan] = -1;
                    freeMen.add(currentMan);
                } else {
                    // Woman rejects proposal
                    freeMen.add(m);
                }
            }
        }

        return wifeOfMan;
    }
}
