class Solution {
    ArrayList<Integer> findTwoElement(int arr[]) {
        int n = arr.length;
        int repeating = -1, missing = -1;

        // STEP 1: Find repeating using index marking
        for (int i = 0; i < n; i++) {
            int idx = Math.abs(arr[i]) - 1;  

            // If already negative, this number was seen before
            if (arr[idx] < 0) {
                repeating = Math.abs(arr[i]);
            } else {
                arr[idx] = -arr[idx];
            }
        }

        // STEP 2: Find missing (index that is still positive)
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(repeating);
        ans.add(missing);

        return ans;
    }
}
