class Solution {
    public ArrayList<Integer> largestSubset(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        List<Integer>[] chainList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            chainList[i] = new ArrayList<>();
            chainList[i].add(arr[i]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        chainList[i] = new ArrayList<>(chainList[j]);
                        chainList[i].add(arr[i]);
                    } else if (dp[j] + 1 == dp[i]) {
                        boolean update = false;
                        for (int k = 0; k < chainList[j].size(); k++) {
                            int a = chainList[j].get(k);
                            int b = chainList[i].get(k);
                            if (a > b) {
                                update = true;
                                break;
                            } else if (a < b) {
                                break;
                            }
                        }
                        if (update) {
                            List<Integer> newList = new ArrayList<>(chainList[j]);
                            newList.add(arr[i]);
                            chainList[i] = newList;
                        }
                    }
                }
            }
        }
        
        int maxLen = 0;
        List<Integer> bestChain = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                bestChain = chainList[i];
            } else if (dp[i] == maxLen) {
                for (int k = 0; k < dp[i]; k++) {
                    int a = chainList[i].get(k);
                    int b = bestChain.get(k);
                    if (a > b) {
                        bestChain = chainList[i];
                        break;
                    } else if (a < b) {
                        break;
                    }
                }
            }
        }
        
        return new ArrayList<>(bestChain);
    }

}
