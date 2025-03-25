//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;

class GFG {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            Solution obj = new Solution();
            System.out.println(obj.countWays(s));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
       static int countWays(String s) {
        int n = s.length();
        int m = (n + 1) / 2; // Number of symbols (T/F)
        if (m == 0) return 0;
        
        char[] symbols = new char[m];
        char[] ops = new char[m - 1];
        
        // Separate symbols and operators
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) symbols[i / 2] = s.charAt(i);
            else ops[i / 2] = s.charAt(i);
        }
        
        long[][] T = new long[m][m]; // True counts
        long[][] F = new long[m][m]; // False counts
        
        // Base case: single symbol
        for (int i = 0; i < m; i++) {
            if (symbols[i] == 'T') {
                T[i][i] = 1;
                F[i][i] = 0;
            } else {
                T[i][i] = 0;
                F[i][i] = 1;
            }
        }
        
        // Fill DP tables
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i <= m - len; i++) {
                int j = i + len - 1;
                T[i][j] = 0;
                F[i][j] = 0;
                
                for (int k = i; k < j; k++) {
                    char op = ops[k];
                    long leftT = T[i][k];
                    long leftF = F[i][k];
                    long rightT = T[k+1][j];
                    long rightF = F[k+1][j];
                    
                    switch (op) {
                        case '&':
                            T[i][j] += leftT * rightT;
                            F[i][j] += leftT*rightF + leftF*rightT + leftF*rightF;
                            break;
                        case '|':
                            T[i][j] += leftT*rightT + leftT*rightF + leftF*rightT;
                            F[i][j] += leftF * rightF;
                            break;
                        case '^':
                            T[i][j] += leftT*rightF + leftF*rightT;
                            F[i][j] += leftT*rightT + leftF*rightF;
                            break;
                    }
                }
            }
        }
        
        return (int) T[0][m-1];
    }
}
