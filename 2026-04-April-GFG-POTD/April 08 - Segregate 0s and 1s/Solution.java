class Solution {
    void segregate0and1(int[] arr) {
        int countZero = 0;

        for (int num : arr) {
            if (num == 0) countZero++;
        }

        for (int i = 0; i < arr.length; i++) {
            if (i < countZero) arr[i] = 0;
            else arr[i] = 1;
        }
    }
}

