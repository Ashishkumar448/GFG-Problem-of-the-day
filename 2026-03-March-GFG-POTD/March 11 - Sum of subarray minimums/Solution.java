class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.length;
        
        int[] ple = new int[n]; // previous less
        int[] nle = new int[n]; // next less
        
        Stack<Integer> stack = new Stack<>();
        
        // Previous Less Element
        for(int i = 0; i < n; i++){
            while(!stack.isEmpty() && arr[stack.peek()] > arr[i]){
                stack.pop();
            }
            
            ple[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }
        
        stack.clear();
        
        // Next Less Element
        for(int i = n - 1; i >= 0; i--){
            while(!stack.isEmpty() && arr[stack.peek()] >= arr[i]){
                stack.pop();
            }
            
            nle[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }
        
        long sum = 0;
        
        for(int i = 0; i < n; i++){
            long left = i - ple[i];
            long right = nle[i] - i;
            
            sum += (long)arr[i] * left * right;
        }
        
        return (int)sum;
    }
}
