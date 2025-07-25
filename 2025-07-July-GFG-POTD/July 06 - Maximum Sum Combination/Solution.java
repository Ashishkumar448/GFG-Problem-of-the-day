class Solution {
    public ArrayList<Integer> topKSumPairs(int[] a, int[] b, int k) {
        Arrays.sort(a);
        Arrays.sort(b);
        int n = a.length;

        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((x, y) -> y.sum - x.sum);
        Set<String> visited = new HashSet<>();

        int i = n - 1, j = n - 1;
        maxHeap.offer(new Pair(i, j, a[i] + b[j]));
        visited.add(i + "_" + j);

        ArrayList<Integer> result = new ArrayList<>();

        while (k-- > 0 && !maxHeap.isEmpty()) {
            Pair current = maxHeap.poll();
            result.add(current.sum);
            i = current.i;
            j = current.j;

            // Move in a[] to the left (i-1, j)
            if (i - 1 >= 0 && !visited.contains((i - 1) + "_" + j)) {
                maxHeap.offer(new Pair(i - 1, j, a[i - 1] + b[j]));
                visited.add((i - 1) + "_" + j);
            }

            // Move in b[] to the left (i, j-1)
            if (j - 1 >= 0 && !visited.contains(i + "_" + (j - 1))) {
                maxHeap.offer(new Pair(i, j - 1, a[i] + b[j - 1]));
                visited.add(i + "_" + (j - 1));
            }
        }

        return result;
    }

    static class Pair {
        int i, j, sum;
        Pair(int i, int j, int sum) {
            this.i = i;
            this.j = j;
            this.sum = sum;
        }
    }

}
