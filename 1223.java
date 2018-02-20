import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[][] c = new BigInteger[64][64];
    static BigInteger[] ans = new BigInteger[64];

    public static void main(String[] args) {

        int i, j;
    	c[0][0] = BigInteger.ONE;
        for (i = 1; i <= 50; ++ i) {
            c[i][0] = BigInteger.ONE;
            c[i][i] = BigInteger.ONE;
            for (j = 1; j < i; ++ j)
                c[i][j] = c[i-1][j].add(c[i-1][j-1]);
        }

        ans[1] = BigInteger.ONE;
        for (i = 2; i <= 50; ++ i) {
            ans[i] = BigInteger.ONE;
            for (j = i-1; j > 0; -- j) 
                ans[i] = ans[i].add(c[i][j].multiply(ans[j]));
        }

        Scanner cin = new Scanner(System.in);
        int n;

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(ans[n]);
        }
    }
}