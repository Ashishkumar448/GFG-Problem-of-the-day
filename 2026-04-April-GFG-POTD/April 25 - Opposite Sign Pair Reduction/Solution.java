class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        
        for (int num : arr) {
            boolean add = true;
            
            while (!stack.isEmpty()) {
                int top = stack.peek();
                
                // Check opposite signs
                if ((top > 0 && num < 0) || (top < 0 && num > 0)) {
                    stack.pop();
                    
                    if (Math.abs(top) > Math.abs(num)) {
                        num = top; // keep top
                    } else if (Math.abs(top) < Math.abs(num)) {
                        // keep current num
                    } else {
                        // equal → both removed
                        add = false;
                        break;
                    }
                } else {
                    break;
                }
            }
            
            if (add) {
                stack.push(num);
            }
        }
        
        return new ArrayList<>(stack);
    }
}
