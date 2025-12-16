class Solution {
    // Function to check if two strings are rotations of each other or not.
    public boolean areRotations(String s1, String s2) {
        // 1. Basic Length Check
        if (s1.length() != s2.length()) {
            return false;
        }
        
        int n = s1.length();
        if (n == 0) return true; 

        // 2. Compute LPS (Longest Prefix Suffix) array for s2 (the pattern)
        // This pre-processing allows us to skip characters efficiently on mismatch
        int[] lps = new int[n];
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (s2.charAt(i) == s2.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // 3. KMP Search on virtual (s1 + s1)
        // We use 'i % n' to simulate traversing s1 concatenated with itself
        // without actually allocating extra memory.
        int j = 0; // index for s2
        i = 0; // index for s1
        
        // We iterate up to 2*n because the rotated string must be found within s1+s1
        while (i < 2 * n) {
            // Compare s2[j] with s1[i % n]
            if (s2.charAt(j) == s1.charAt(i % n)) {
                j++;
                i++;
                // If we have matched the entire s2 string
                if (j == n) {
                    return true;
                }
            } else {
                // Mismatch after some matches
                if (j != 0) {
                    j = lps[j - 1]; // Use LPS to skip comparisons
                } else {
                    i++;
                }
            }
        }
        
        return false;
    }
}
