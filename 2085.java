import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger[] f = new BigInteger[64];
    static BigInteger[] g = new BigInteger[64];
    static BigInteger san = new BigInteger("3");
    static BigInteger er = new BigInteger("2");
    static int n;

    public static void main(String []args) {

        f[0] = BigInteger.ONE;
        g[0] = BigInteger.ZERO;
        for (n = 1; n <= 50; ++ n) {
            f[n] = f[n - 1].multiply(san).add(g[n - 1].multiply(er));
            g[n] = f[n - 1].add(g[n - 1]);
        }
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n < 0) break;
            System.out.println(f[n].toString() + ", " + g[n].toString());
        }
    }
}