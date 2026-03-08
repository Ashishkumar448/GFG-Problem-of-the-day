class Solution {
    boolean pythagoreanTriplet(int[] arr) {
        int n = arr.length;
        
        boolean[] present = new boolean[1000001];

        // store squares
        for(int i = 0; i < n; i++){
            int sq = arr[i] * arr[i];
            present[sq] = true;
        }

        // check pairs
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if(sum <= 1000000 && present[sum]){
                    return true;
                }
            }
        }

        return false;
    }
}
