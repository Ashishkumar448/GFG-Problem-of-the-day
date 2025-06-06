class Solution {
     public ArrayList<Integer> search(String pat, String txt) {
        ArrayList<Integer> result = new ArrayList<>();

        int m = pat.length();
        int n = txt.length();
        int d = 256; // Number of characters in the input alphabet (ASCII)
        int q = 101; // A prime number to mod the hash values (helps reduce collisions)
        int h = 1;
        int p = 0; // Hash value for pattern
        int t = 0; // Hash value for text

        // The value of h would be "pow(d, m-1) % q"
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pat.charAt(i)) % q;
            t = (d * t + txt.charAt(i)) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // If the hash values match, then only check characters one by one
            if (p == t) {
                int j;
                for (j = 0; j < m; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j))
                        break;
                }
                if (j == m)
                    result.add(i + 1); // 1-based indexing
            }

            // Calculate hash value for next window of text
            // Remove leading digit, add trailing digit
            if (i < n - m) {
                t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + m)) % q;

                // We might get a negative value of t, converting it to positive
                if (t < 0)
                    t = (t + q);
            }
        }

        return result;
    }
}
