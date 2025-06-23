class Solution {
   String minSum(int[] arr) {
        // Step 1: Sort the array
        Arrays.sort(arr);

        // Step 2: Build two numbers from the digits
        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();

        for (int i = 0; i < arr.length; i++) {
            if (i % 2 == 0) {
                num1.append(arr[i]);
            } else {
                num2.append(arr[i]);
            }
        }

        // Step 3: Add the two numbers (as strings)
        String result = addStrings(num1.toString(), num2.toString());

        // Step 4: Remove leading zeros
        int i = 0;
        while (i < result.length() - 1 && result.charAt(i) == '0') {
            i++;
        }

        return result.substring(i);
    }

    // Helper method to add two large numbers represented as strings
    String addStrings(String num1, String num2) {
        StringBuilder result = new StringBuilder();

        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = i >= 0 ? num1.charAt(i--) - '0' : 0;
            int digit2 = j >= 0 ? num2.charAt(j--) - '0' : 0;

            int sum = digit1 + digit2 + carry;
            result.append(sum % 10);
            carry = sum / 10;
        }

        // The result is reversed
        return result.reverse().toString();
    }
}
 
