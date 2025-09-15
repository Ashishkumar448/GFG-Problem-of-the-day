class Solution {
    public boolean stringStack(String pat, String tar) {
        int i = pat.length() - 1;
        int j = tar.length() - 1;

        while (i >= 0 && j >= 0) {
            if (pat.charAt(i) == tar.charAt(j)) {
                // use pat[i] to match tar[j]
                i--;
                j--;
            } else {
                // use pat[i] as a delete operation -> it deletes
                // the previous appended character, so skip two positions
                i -= 2;
            }
        }
        // if we've matched all characters of tar, success
        return j < 0;
    }
}
