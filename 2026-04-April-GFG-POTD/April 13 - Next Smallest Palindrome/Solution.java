class Solution {
    static int[] nextPalindrome(int[] num) {
        int n = num.length;

        // 🔥 Step 0: Check if all digits are 9
        boolean all9 = true;
        for (int x : num) {
            if (x != 9) {
                all9 = false;
                break;
            }
        }

        if (all9) {
            int[] res = new int[n + 1];
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        int[] res = num.clone();

        // Step 1: Mirror left to right
        for (int i = 0; i < n / 2; i++) {
            res[n - 1 - i] = res[i];
        }

        // Step 2: Check if mirrored is greater
        boolean isGreater = false;
        for (int i = 0; i < n; i++) {
            if (res[i] > num[i]) {
                isGreater = true;
                break;
            } else if (res[i] < num[i]) {
                break;
            }
        }

        if (isGreater) return res;

        // Step 3: Increment middle
        int carry = 1;
        int mid = (n - 1) / 2;

        while (mid >= 0 && carry > 0) {
            int sum = res[mid] + carry;
            res[mid] = sum % 10;
            carry = sum / 10;
            mid--;
        }

        // Step 4: Mirror again
        for (int i = 0; i < n / 2; i++) {
            res[n - 1 - i] = res[i];
        }

        return res;
    }
}
