class Solution:
    def countValid(self, n, arr):
        include_set = set(arr)

        # Step 1: Total n-digit numbers
        if n == 1:
            total = 9
        else:
            total = 9 * (10 ** (n - 1))

        # Step 2: Complement digits
        complement = [i for i in range(10) if i not in include_set]

        # If no complement digits, all numbers are valid
        if not complement:
            return total

        # Step 3: Count invalid numbers
        first_digit_choices = sum(1 for d in complement if d != 0)
        length = len(complement)

        if n == 1:
            invalid = first_digit_choices
        else:
            invalid = first_digit_choices * (length ** (n - 1))

        # Step 4: Valid = Total - Invalid
        return total - invalid
