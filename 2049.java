import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] d = new BigInteger[32];
    static BigInteger[][] c = new BigInteger[32][32];
    static BigInteger[] num = new BigInteger[32];
    static int n, m;

    public static void main(String []args) {

        num[0] = BigInteger.ZERO;
        for (n = 1; n <= 30; ++ n)
            num[n] = num[n-1].add(BigInteger.ONE);
        d[1] = num[0];
        d[2] = num[1];
        for (n = 3; n <= 30; ++ n)
            d[n] = num[n-1].multiply(d[n-1].add(d[n-2]));
        c[0][0] = num[1];
        for (n = 1; n <= 30; ++ n) {
            c[n][0] = num[1];
            c[n][n] = num[1];
            for (m = 1; m < n; ++ m)
                c[n][m] = c[n-1][m].add(c[n-1][m-1]);
        }

        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            System.out.println(c[n][m].multiply(d[m]));
        }
    }
}