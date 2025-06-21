class Solution {
   public int catchThieves(char[] arr, int k) {
        int n = arr.length;
        int count = 0;

        Queue<Integer> police = new LinkedList<>();
        Queue<Integer> thief = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.add(i);
            } else if (arr[i] == 'T') {
                thief.add(i);
            }

            while (!police.isEmpty() && !thief.isEmpty()) {
                int polIndex = police.peek();
                int thiefIndex = thief.peek();

                if (Math.abs(polIndex - thiefIndex) <= k) {
                    count++;
                    police.poll();
                    thief.poll();
                } else if (thiefIndex < polIndex) {
                    thief.poll();
                } else {
                    police.poll();
                }
            }
        }

        return count;
    }
}
