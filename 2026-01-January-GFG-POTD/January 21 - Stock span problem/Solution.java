class Solution {
    public ArrayList<Integer> calculateSpan(int[] arr) {
        ArrayList<Integer> span = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < arr.length; i++) {

            // Pop while current price is higher or equal
            while (!stack.isEmpty() && arr[stack.peek()] <= arr[i]) {
                stack.pop();
            }

            // If stack is empty, span is i + 1
            int currSpan = stack.isEmpty() ? i + 1 : i - stack.peek();
            span.add(currSpan);

            // Push current index
            stack.push(i);
        }

        return span;
    }
}
