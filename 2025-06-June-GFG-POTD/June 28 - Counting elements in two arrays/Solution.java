class Solution {
    public static ArrayList<Integer> countLessEq(int a[], int b[]) {
        ArrayList<Integer> result = new ArrayList<>();
        
        // Step 1: Sort array b
        Arrays.sort(b);
        
        // Step 2: For each element in a[], perform binary search in b[]
        for (int num : a) {
            int count = upperBound(b, num);
            result.add(count);
        }
        
        return result;
    }

    // Function to find count of elements <= x using binary search
    private static int upperBound(int[] arr, int x) {
        int low = 0, high = arr.length;

        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;  // number of elements <= x
    }
}
