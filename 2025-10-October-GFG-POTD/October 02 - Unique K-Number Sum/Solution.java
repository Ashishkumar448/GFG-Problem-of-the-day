class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), n, k, 1, 0);
        return result;
    }
    
    private void backtrack(ArrayList<ArrayList<Integer>> result, 
                           ArrayList<Integer> temp, 
                           int target, int k, int start, int sum) {
        // if we have k numbers chosen
        if (temp.size() == k) {
            if (sum == target) {
                result.add(new ArrayList<>(temp));
            }
            return;
        }
        
        // try all numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            if (sum + i > target) break; // pruning
            temp.add(i);
            backtrack(result, temp, target, k, i + 1, sum + i);
            temp.remove(temp.size() - 1); // backtrack
        }
    }
}
