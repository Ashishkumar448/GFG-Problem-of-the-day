class Solution {
    public static ArrayList<ArrayList<Integer>> permuteDist(int[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        backtrack(arr, 0, res);
        return res;
    }

    private static void backtrack(int[] arr, int idx, ArrayList<ArrayList<Integer>> res) {
        if (idx == arr.length) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int x : arr) temp.add(x);
            res.add(temp);
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            swap(arr, i, idx);
            backtrack(arr, idx + 1, res);
            swap(arr, i, idx); // backtrack
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};
