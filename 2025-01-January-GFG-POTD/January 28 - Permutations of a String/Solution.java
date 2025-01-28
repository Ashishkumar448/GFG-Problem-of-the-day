//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            ArrayList<String> ans = obj.findPermutation(S);
            Collections.sort(ans);
            for (int i = 0; i < ans.size(); i++) {
                out.print(ans.get(i) + " ");
            }
            out.println();

            out.println("~");
        }
        out.close();
    }
}

// } Driver Code Ends


class Solution {
     public ArrayList<String> findPermutation(String s) {
        ArrayList<String> result = new ArrayList<>();
        char[] chars = s.toCharArray();
        Arrays.sort(chars); // Sort to handle duplicates easily
        boolean[] used = new boolean[s.length()];
        backtrack(result, new StringBuilder(), chars, used);
        return result;
    }

    private void backtrack(ArrayList<String> result, StringBuilder current, char[] chars, boolean[] used) {
        if (current.length() == chars.length) {
            result.add(current.toString());
            return;
        }

        for (int i = 0; i < chars.length; i++) {
            // Skip already used characters
            if (used[i]) continue;

            // Skip duplicates (only use the first occurrence)
            if (i > 0 && chars[i] == chars[i - 1] && !used[i - 1]) continue;

            // Mark the character as used
            used[i] = true;
            current.append(chars[i]);

            // Recursive call
            backtrack(result, current, chars, used);

            // Backtrack
            current.deleteCharAt(current.length() - 1);
            used[i] = false;
        }
    }
}
